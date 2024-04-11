#include <stdio.h>
#include <vector>
using namespace std;
const int N=105;
vector<int> E[N];
int ans,sol;
int max(int a, int b){ return a>b?a:b;}
int DFS(int c, int p, int d)
{
	int Best=d,i;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p)
		{
			int tmp=DFS(v,c,d+1);
			ans=max(ans,Best+tmp-2*d);
			Best=max(Best,tmp);
		}
	}
	return Best;
}
void Add()
{
	ans=0;
	DFS(1,0,0);
	sol+=ans;
	for(int i=0;i<N;i++) E[i].clear();
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,x,u,v;
	scanf("%i",&n);
	while(n --> 0)
	{
		scanf("%i",&x);
		while(0 <-- x)
		{
			scanf("%i %i",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		Add();
	}
	printf("%i\n",sol);
	return 0;
}