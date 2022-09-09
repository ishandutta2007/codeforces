#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
int NodeSize[N],anc[N],par[N],Depth[N];
vector<int> E,D;
int logs[N<<1],ST[N<<1][20],FAI[N];
void DFS(int cur, int prev, int depth)
{
	FAI[cur]=E.size();
	E.push_back(cur);
	D.push_back(depth);
	Depth[cur]=depth;
	par[cur]=prev;
	anc[cur]=cur;
	NodeSize[cur]=1;
	int i;
	if(depth>200) for(i=0;i<200;i++) anc[cur]=par[anc[cur]];
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur,depth+1);
			NodeSize[cur]+=NodeSize[v];
			E.push_back(cur);
			D.push_back(depth);
		}
	}
}
void Preprocess()
{
	int i,k=0;
	for(i=0;i<N<<1;i++)
	{
		if(i==1<<k+1) k++;
		logs[i]=k;
	}
}
void BuildSparseTable()
{
	Preprocess();
	DFS(1,0,1);
	int n=E.size(),i,j;
	for(i=0;i<n;i++) ST[i][0]=i;
	for(j=1;j<20;j++)
	{
		for(i=0;i<=n-(1<<j);i++)
		{
			if(D[ST[i][j-1]]<D[ST[i+(1<<j-1)][j-1]])
				ST[i][j]=ST[i][j-1];
			else ST[i][j]=ST[i+(1<<j-1)][j-1];
		}
	}
}
int LCA(int u, int v)
{
	if(FAI[u]>FAI[v])
	{
		int tmp=u;
		u=v;
		v=tmp;
	}
	u=FAI[u];
	v=FAI[v]+1;
	int k=logs[v-u];
	if(D[ST[u][k]]<D[ST[v-(1<<k)][k]])
		return E[ST[u][k]];
	else return E[ST[v-(1<<k)][k]];
}
int Dist(int u, int v){ return Depth[u]+Depth[v]-2*Depth[LCA(u,v)];}
int main()
{
	int n,i,j,q,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	BuildSparseTable();
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&u,&v);
		if(u==v) printf("%i\n",n);
		else
		{
			if(Depth[u]==Depth[v])
			{
				int lca=LCA(u,v);
				int goal=Depth[lca]+1;
				while(Depth[u]-200>goal) u=anc[u];
				while(Depth[u]>goal) u=par[u];
				while(Depth[v]-200>goal) v=anc[v];
				while(Depth[v]>goal) v=par[v];
				//printf("%i %i ",u,v);
				printf("%i\n",n-NodeSize[u]-NodeSize[v]);
			}
			else if(Dist(u,v)%2==0)
			{
				if(Depth[u]>Depth[v])
				{
					int tmp=u;
					u=v;
					v=tmp;
				}
				int lca=LCA(u,v);
				int goal=Depth[v]-Dist(u,v)/2+1;
				while(Depth[v]-200>goal) v=anc[v];
				while(Depth[v]>goal) v=par[v];
				printf("%i\n",NodeSize[par[v]]-NodeSize[v]);
			}
			else printf("0\n");
		}
	}
	return 0;
}