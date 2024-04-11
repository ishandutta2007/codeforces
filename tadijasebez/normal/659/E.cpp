#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N];
int Depth[N];
bool vis[N];
bool DFS(int cur, int prev, int depth)
{
	vis[cur]=true;
	Depth[cur]=depth;
	bool ok=true;
	int i;
	for(i=0;i<E[cur].size();i++)
	{
		int v=E[cur][i];
		if(!vis[v])
		{
			bool tmp=DFS(v,cur,depth+1);
			ok=ok&tmp;
		}
		else if(Depth[v]>depth) ok=false;
	}
	return ok;
}
int sol;
int main()
{
	int n,m,u,v,i;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i",&u,&v),E[u].push_back(v),E[v].push_back(u);
	for(i=1;i<=n;i++) if(!vis[i]) sol+=DFS(i,0,1);
	printf("%i\n",sol);
	return 0;
}