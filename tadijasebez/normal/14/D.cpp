#include <stdio.h>
#include <vector>
using namespace std;
const int N=205;
vector<int> Tree[N];
int ans,sol,ret;
int max(int a, int b){ return a>b?a:b;}
int DFS(int cur, int prev, int depth)
{
	int best=depth;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			int tmp=DFS(v,cur,depth+1);
			ans=max(ans,best+tmp-2*depth);
			best=max(best,tmp);
		}
	}
	return best;
}
int u[N],v[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u[i],&v[i]);
		Tree[u[i]].push_back(v[i]);
		Tree[v[i]].push_back(u[i]);
	}
	for(i=1;i<n;i++)
	{
		ans=0;
		DFS(u[i],v[i],1);
		sol=ans;
		ans=0;
		DFS(v[i],u[i],1);
		ret=max(ret,ans*sol);
	}
	printf("%i\n",ret);
	return 0;
}