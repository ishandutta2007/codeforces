#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=200050;
vector<int> E[N];
int lid[N],rid[N],tid,sz[N],nod[N];
void DFS(int u)
{
	lid[u]=++tid;
	nod[tid]=u;
	sz[u]=1;
	for(int i=0;i<E[u].size();i++) DFS(E[u][i]),sz[u]+=sz[E[u][i]];
	rid[u]=tid;
}
int main()
{
	int n,x,i,q,k;
	scanf("%i %i",&n,&q);
	for(i=2;i<=n;i++) scanf("%i",&x),E[x].pb(i);
	DFS(1);
	while(q--)
	{
		scanf("%i %i",&x,&k);
		if(sz[x]<k) printf("-1\n");
		else printf("%i\n",nod[lid[x]+k-1]);
	}
	return 0;
}