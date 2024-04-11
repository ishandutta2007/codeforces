#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
int good[N];
int a[N],b[N];
vector<int> sol;
void DFS(int cur, int prev, int depth, int odd, int even)
{
	if(depth%2==0)
	{
		if(even==good[cur])
		{
			sol.push_back(cur+1);
			even^=1;
		}
	}
	else
	{
		if(odd==good[cur])
		{
			sol.push_back(cur+1);
			odd^=1;
		}
	}
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev) DFS(v,cur,depth+1,odd,even);
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		u--;
		v--;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	for(i=0;i<n;i++) scanf("%i",&b[i]);
	for(i=0;i<n;i++) good[i]=(a[i]==b[i]);
	DFS(0,0,0,0,0);
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i\n",sol[i]);
	return 0;
}