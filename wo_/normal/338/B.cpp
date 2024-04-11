#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int inf=1<<25;

vector<int> G[100100];
int M[2][100100];
int U[100100];

bool a[100100];

int par[100100];

int dfs(int v,int p)
{
	par[v]=p;
	int m=-inf;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i];
		if(u==p) continue;
		m=max(m,dfs(u,v)+1);
	}
	if(a[v]==true) m=max(m,0);
	M[0][v]=m;
	return m;
}

vector<int> tmp;
void dfs2(int v,int p)
{
	tmp.clear();
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		if(M[0][G[v][i]]!=-inf)
		{
		//	printf("%d-%d\n",v,G[v][i]);
			tmp.push_back(M[0][G[v][i]]);
		}
	}
	sort(tmp.begin(),tmp.end());
	if(tmp.size()>=2)
	{
	//	printf("%d\n",v);
		M[1][v]=tmp[tmp.size()-2]+1;
	}
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs2(G[v][i],v);
	}
}

void dfs3(int v,int p)
{
	int m;
	if(v==0) goto gonxt;
	m=(M[0][p]==M[0][v]+1)?M[1][p]+1:M[0][p]+1;
	m=max(m,U[p]+1);
	if(a[v]) m=max(m,0);
	U[v]=m;
	gonxt:;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs3(G[v][i],v);
	}
}

int main()
{
	int N,M_,D;
	scanf("%d%d%d",&N,&M_,&D);
	for(int i=0;i<100100;i++) a[i]=false;
	for(int i=0;i<M_;i++)
	{
		int v;
		scanf("%d",&v);
		v--;
		a[v]=true;
	}
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<2;i++) for(int j=0;j<100100;j++) M[i][j]=-(inf);
	for(int i=0;i<100100;i++) U[i]=-(inf);
	if(a[0]) U[0]=0;
	dfs(0,-1);
	dfs2(0,-1);
	dfs3(0,-1);
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		if(M[0][i]<=D&&U[i]<=D) cnt++;
	}
/*	for(int i=0;i<N;i++) printf("%d ",M[0][i]);
	printf("\n");
	for(int i=0;i<N;i++) printf("%d ",M[1][i]);
	printf("\n");
	for(int i=0;i<N;i++) printf("%d ",U[i]);
	printf("\n");*/
	printf("%d\n",cnt);
	return 0;
}