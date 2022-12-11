#include<bits/stdc++.h>
using namespace std;
int n,mod;
inline void upd(int &x)
{
	x-=x>=mod?mod:0;
}
const int max_n=2e3+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
int dp[max_n][max_n],S[max_n][max_n];
int pre_now[max_n][max_n],suf_now[max_n][max_n],pre[max_n][max_n],suf[max_n][max_n];
void dfs(int x,int fa)
{
	for(int i=1;i<=n;++i)
		pre_now[x][i]=suf_now[x][i]=1;
	vector<int> son;
	for(int k=Last[x];k;k=Next[k])
	{
		int y=End[k];
		if(y!=fa)
		{
			dfs(y,x);
			son.push_back(y);
			for(int i=1;i<=n;++i)
			{
				pre[y][i]=pre_now[x][i];
				pre_now[x][i]=1ll*pre_now[x][i]*S[y][i]%mod;
			}
		}
	}
	for(int i=1;i<=n;++i)
		dp[x][i]=pre_now[x][i];
	if(x!=1)
	{
		for(int k=int(son.size())-1;k>=0;--k)
		{
			int y=son[k];
			for(int i=1;i<=n;++i)
			{
				suf[y][i]=suf_now[x][i];
				suf_now[x][i]=1ll*suf_now[x][i]*S[y][i]%mod;
			}
		}
		for(int k=0;k<int(son.size());++k)
		{
			int y=son[k],sum=0;
			for(int i=1;i<=n;++i)
			{
				dp[x][i]=(dp[x][i]+1ll*dp[y][i]*sum)%mod;
				sum=(sum+1ll*pre[y][i]*suf[y][i])%mod;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		S[x][i]=S[x][i-1]+dp[x][i];
		upd(S[x][i]);
	}
}
int C[max_n][max_n],Ans[max_n]; 
int main()
{
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs(1,0);
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			upd(C[i][j]);
		}
	}
	for(int i=1;i<=n-1;++i)
	{
		int res=0;
		for(int j=0;j<=i-1;++j)
			res=(res+1ll*C[i][j]*Ans[j])%mod;
		Ans[i]=dp[1][i]+mod-res;
		upd(Ans[i]);
		printf("%d%c",Ans[i],i<n-1?' ':'\n');
	}
	return 0;
}