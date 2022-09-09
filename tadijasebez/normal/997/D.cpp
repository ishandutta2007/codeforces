#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=4050;
const int K=40;
const int M=N*4*K;
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int k;
struct Tree
{
	int n;
	vector<int> E[N];
	Tree(){}
	void init(int _n){ n=_n;}
	void AddEdge(int u, int v){ E[u].pb(v),E[v].pb(u);}
	int dp[N][K],tmp[N][K],ans[K];
	void DFS(int u, int p)
	{
		dp[u][0]=1;
		for(int v:E[u]) if(v!=p)
		{
			DFS(v,u);
			for(int i=1;i<=k;i++)
				tmp[u][i]=add(tmp[u][i],dp[v][i-1]);
		}
		for(int i=1;i<=k;i++)
			for(int j=0;j<i;j++)
				dp[u][i]=add(dp[u][i],mul(dp[u][j],tmp[u][i-j]));
	}
	void Solve(int u, int p)
	{
		for(int v:E[u]) if(v!=p)
		{
			for(int i=k;i>=1;i--)
				for(int j=0;j<i;j++)
					for(int l=0;i-j-l-1>=0;l++)
						dp[v][i]=add(dp[v][i],mul(dp[v][j],mul(dp[u][l],dp[v][i-j-l-1])));
			Solve(v,u);
		}
		for(int i=0;i<=k;i++)
			ans[i]=add(ans[i],dp[u][i]);
	}
	void Solve()
	{
		DFS(1,0);
		Solve(1,0);
	}
} Tree1,Tree2;
int binom[K*2][K*2];
int main()
{
	int n1,n2,u,v;
	scanf("%i %i %i",&n1,&n2,&k);
	if(k&1) return 0*printf("0\n");
	k/=2;
	Tree1.init(n1);
	Tree2.init(n2);
	for(int i=1;i<n1;i++) scanf("%i %i",&u,&v),Tree1.AddEdge(u,v);
	for(int i=1;i<n2;i++) scanf("%i %i",&u,&v),Tree2.AddEdge(u,v);
	binom[0][0]=1;
	for(int i=1;i<K*2;i++) for(int j=0;j<K*2;j++)
		binom[i][j]=add(binom[i-1][j],j>0?binom[i-1][j-1]:0);
	Tree1.Solve();
	Tree2.Solve();
	int ans=0;
	for(int i=0;i<=k;i++)
		ans=add(ans,mul(binom[k*2][i*2],mul(Tree1.ans[i],Tree2.ans[k-i])));
	printf("%i\n",ans);
	return 0;
}