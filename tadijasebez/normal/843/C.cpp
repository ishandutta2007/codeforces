#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
vector<int> Tree[N];
int Size[N];
int n;
int isCen[N];
vector<int> Cen;
void CalcSize(int cur, int prev)
{
	Size[cur]=1;
	isCen[cur]=true;
	for(int i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			CalcSize(v,cur);
			Size[cur]+=Size[v];
			if(Size[v]>n/2) isCen[cur]=false;
		}
	}
	if(n-Size[cur]>n/2) isCen[cur]=false;
	if(isCen[cur]) Cen.push_back(cur);
}
struct Data
{
	int x,y,y1;
	Data (){}
	Data (int a, int b, int c)
	{
		x=a;
		y=b;
		y1=c;
	}
};
vector<Data> ans;
int last;
void Solve(int cur, int prev, int cen, int first)
{
	if(cur!=first)
	{
		ans.push_back(Data(cen,last,cur));
		ans.push_back(Data(cur,prev,first));
		last=cur;
	}
	for(int i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
			Solve(v,cur,cen,first);
	}
}
int main()
{
	int i,u,v,j;
	scanf("%i",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	CalcSize(1,1);
	for(i=0;i<Cen.size();i++)
	{
		u=Cen[i];
		for(j=0;j<Tree[u].size();j++)
		{
			v=Tree[u][j];
			if(!isCen[v])
			{
				last=v;
				Solve(v,u,u,v);
				ans.push_back(Data(u,last,v));
			}
		}
	}
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%i %i %i\n",ans[i].x,ans[i].y,ans[i].y1);
	}
	return 0;
}