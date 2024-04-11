#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
	int to;
	bool which;//right or wrong direction
	bool up;//up:true,down:false;
	edge(){}
	edge(int a,bool b):to(a),which(b){}
};

vector<edge> G[3300];

int par[3300];
int ups[3300];//up edge in the subtree

int dp[3300];
int cnt=0;

int dfs(int v,int p)
{
	par[v]=p;
	int c=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==p) continue;
		if(G[v][i].which==true) G[v][i].up=false;
		else G[v][i].up=true;
		c+=dfs(G[v][i].to,v);
		if(G[v][i].up==true) c++;
	}
	ups[v]=c;
	return c;
}

int rec(int v)
{
	int M=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==par[v]) continue;
		int tmp=rec(G[v][i].to);
		if(G[v][i].up==true) tmp++;
		else tmp--;
		M=max(M,tmp);
	}
	dp[v]=M;
	return M;
}

int sum[3300];

void setsum(int v,int s)
{
	sum[v]=s;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==par[v]) continue;
		if(G[v][i].up==true) setsum(G[v][i].to,s+1);
		else setsum(G[v][i].to,s-1);
	}
}

int get(int v,int other)
{
	if(v==other) return 33000;
	int m=ups[0]-ups[other]-sum[v];
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==par[v]) continue;
		m=min(m,get(G[v][i].to,other));
	}
	return m;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		G[a].push_back(edge(b,true));
		G[b].push_back(edge(a,false));
	}
	dfs(0,-1);
	rec(0);
	setsum(0,0);
	int ans=ups[0]-dp[0];//reign by one person
	for(int i=1;i<N;i++)
	{
		int p=par[i];
		int tmp;
		bool flg;
		for(int j=0;j<G[p].size();j++)
		{
			if(G[p][j].to==i)
			{
				flg=G[p][j].up;
			}
		}
		tmp=ups[i]-dp[i];
		tmp+=get(0,i);
		if(flg) tmp--;
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}