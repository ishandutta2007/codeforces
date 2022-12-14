#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;
const int inf=1<<29;

vector<int> G[100100];

int ans[100100];

bool centroid[100100];
int subsize[100100];

int get_subsize(int v,int p)
{
	int c=1;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p||centroid[G[v][i]]) continue;
		c+=get_subsize(G[v][i],v);
	}
	subsize[v]=c;
	return c;
}

P search_centroid(int v,int p,int t)
{
	P res=P(inf,-1);
	int s=1,m=0;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i];
		if(u==p||centroid[u]) continue;
		res=min(res,search_centroid(u,v,t));
		m=max(m,subsize[u]);
		s+=subsize[u];
	}
	m=max(m,t-s);
	res=min(res,P(m,v));
	return res;
}

void solve(int v,int rank)
{
	//printf("%d %d\n",v,rank);
	get_subsize(v,-1);
	int s=search_centroid(v,-1,subsize[v]).second;
	centroid[s]=true;
	ans[s]=rank;
	for(int i=0;i<G[s].size();i++)
	{
		if(centroid[G[s][i]]) continue;
		solve(G[s][i],rank+1);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve(0,0);
	for(int i=0;i<N;i++)
	{
		printf("%c%c",'A'+ans[i],i==N-1?'\n':' ');
	}
	return 0;
}