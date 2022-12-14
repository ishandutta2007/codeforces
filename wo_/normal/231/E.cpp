#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

const int mod=1000000007;

vector<int> G[100100],rev[100100];
vector<int> tG[100100];

int num[100100];
bool two[100100];

int par[100100][20],times[100100][20],dep[100100];

bool used[100100];

vector<int> vs;

void dfs(int v,int p)
{
	//if(p!=-1) rev[v].push_back(p);
	//vs.push_back(v);
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		rev[G[v][i]].push_back(v);
		if(used[G[v][i]]==true) continue;
		dfs(G[v][i],v);
	}
	vs.push_back(v);
}

int now=0;

void rdfs(int v)
{
	used[v]=true;
	num[v]=now;
	for(int i=0;i<rev[v].size();i++)
	{
		if(used[rev[v][i]]==true) continue;
		rdfs(rev[v][i]);
	}
}

int cnt[100100];

void tdfs(int v,int p,int d)
{
	par[v][0]=p;
	times[v][0]=cnt[v]>=2?1:0;
	dep[v]=d;
	for(int i=0;i<tG[v].size();i++)
	{
		if(tG[v][i]==p) continue;
		tdfs(tG[v][i],v,d+1);
	}
}

int exp[100100];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(used,false,sizeof(used));
	dfs(0,-1);
	memset(used,false,sizeof(used));
	//for(int i=vs.size()-1;i>=0;i--)
	//for(int i=0;i<vs.size();i++)
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(used[vs[i]]==true) continue;
		rdfs(vs[i]);
		now++;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<N;i++)
	{
		cnt[num[i]]++;
		for(int j=0;j<G[i].size();j++)
		{
			if(num[i]==num[G[i][j]]) continue;
			tG[num[i]].push_back(num[G[i][j]]);
		}
	}
	tdfs(0,-1,0);
	for(int i=1;i<20;i++)
	{
		for(int j=0;j<now;j++)
		{
			if(par[j][i-1]==-1) par[j][i]=-1;
			else par[j][i]=par[par[j][i-1]][i-1];
			if(par[j][i-1]==-1) times[j][i]=times[j][i-1];
			else times[j][i]=times[j][i-1]+times[par[j][i-1]][i-1];
		}
	}
	exp[0]=1;
	for(int i=1;i<100100;i++)
	{
		exp[i]=exp[i-1]*2;
		exp[i]%=mod;
	}
	int Q;
	scanf("%d",&Q);
	for(int q=0;q<Q;q++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		int xid=num[x],yid=num[y];
		if(dep[xid]<dep[yid]) swap(xid,yid);
		int c=0;
		int dif=dep[xid]-dep[yid];
		for(int i=19;i>=0;i--)
		{
			if(((dif>>i)&1)==1)
			{
				c+=times[xid][i];
				xid=par[xid][i];
			}
		}
		if(xid==yid)
		{
			c+=times[xid][0];
			printf("%d\n",(int)exp[c]);
			continue;
		}
		for(int i=19;i>=0;i--)
		{
			if(par[xid][i]!=par[yid][i])
			{
				c+=times[xid][i];c+=times[yid][i];
				xid=par[xid][i];yid=par[yid][i];
			}
		}
		c+=times[xid][0];c+=times[yid][0];
		c+=times[par[xid][0]][0];
		printf("%d\n",(int)exp[c]);
	}
	return 0;
}