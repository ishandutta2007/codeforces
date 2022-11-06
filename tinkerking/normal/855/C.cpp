#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
LL f[100010][3][11];
LL N,M;
LL K,X;
vector<int>e[100010];
LL tmp[3][11];

void dfs(int x,int fa)
{
	f[x][0][0] = K-1;
	f[x][1][1] = 1;
	f[x][2][0] = M-K;
	for (auto t:e[x])
	if (t != fa)dfs(t,x);
	for (auto t:e[x])
	if (t != fa)
	{
		for (int i=0;i<3;i++)
			for (int j=0;j<=X;j++) tmp[i][j] = 0;
		for (int i=0;i<=X;i++)
			for (int j=0;j<=i;j++)
			{
				tmp[0][i] = (tmp[0][i] + f[x][0][j] * (f[t][1][i-j] + f[t][0][i-j] + f[t][2][i-j])) % MOD;
				tmp[1][i] = (tmp[1][i] + f[x][1][j] * f[t][0][i-j]) % MOD;
				tmp[2][i] = (tmp[2][i] + f[x][2][j] * (f[t][0][i-j] + f[t][2][i-j])) % MOD;
			}
		for (int i=0;i<3;i++)
			for (int j=0;j<=X;j++)
			f[x][i][j] = tmp[i][j];
	}
	/*
	for (int i=0;i<3;i++)
		for (int j=0;j<=X;j++)
		printf("f[%d][%d][%d]=%lld\n",x,i,j,f[x][i][j]);*/
}

int main()
{
	scanf("%lld%lld",&N,&M);
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	scanf("%lld%lld",&K,&X);
	memset(f,0,sizeof(f));
	dfs(1,0);
	LL ans = 0;
	for (int i=0;i<3;i++)
		for (int j=0;j<=X;j++)
			ans += f[1][i][j];
	ans %= MOD; 
	printf("%lld\n",ans);
}