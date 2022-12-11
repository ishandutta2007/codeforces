#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mpr(a,b) make_pair(a,b) 
#define maxn 105
using namespace std;
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll fastpow(ll a,ll p,ll mod)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x,ll mod){return fastpow(x,mod-2,mod);} 
int T,n,m,k;
char a[maxn][maxn];
int Ans[maxn][maxn];
int nx[maxn][maxn],ny[maxn][maxn];
char ID(int x)
{
	if(1<=x&&x<=26)return x-1+'a';
	if(27<=x&&x<=52)return x-27+'A';
	if(53<=x&&x<=62)return x-53+'0';
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=m+1;++j)nx[i][j]=ny[i][j]=Ans[i][j]=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)nx[i][j]=i,ny[i][j]=(i&1)?j+1:j-1;
			if(i&1)nx[i][m]=i+1,ny[i][m]=m;
			else nx[i][1]=i+1,ny[i][1]=1;
		}
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		int num=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)if(a[i][j]=='R')num++;
		int t=num/k;
		int k1=num-t*k;
		int k2=k-k1;
		int nowx=1,nowy=1;
		for(int p=1;p<=k1;++p)
		{
			int cnt=0;
			while(cnt<t+1)
			{
				Ans[nowx][nowy]=p;
				if(a[nowx][nowy]=='R')cnt++;
				int xx=nx[nowx][nowy],yy=ny[nowx][nowy];
				nowx=xx,nowy=yy;
			}
		}
		for(int p=k1+1;p<=k1+k2;++p)
		{
			int cnt=0;
			while(cnt<t)
			{
				Ans[nowx][nowy]=p;
				if(a[nowx][nowy]=='R')cnt++;
				int xx=nx[nowx][nowy],yy=ny[nowx][nowy];
				nowx=xx,nowy=yy;
			} 
		}
		while(nowx&&nowy)
		{
			Ans[nowx][nowy]=k1+k2;
			int xx=nx[nowx][nowy],yy=ny[nowx][nowy];
			nowx=xx,nowy=yy;
		}
		for(int i=1;i<=n;++i)
		{ 
			for(int j=1;j<=m;++j)printf("%c",ID(Ans[i][j]));
			puts("");
		} 
	}
}