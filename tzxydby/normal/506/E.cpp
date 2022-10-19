#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=205,K=305,mod=10007;
int n,m,dp[N][M][M],g[N],h,ans;
char s[M];
vector<int>BM(vector<int>&a,int mod) 
{
	auto qp=[&](int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;};
	vector<int>ls,cur;
	int f=0,dt=0;
	for(int i=0;i<a.size();i++) 
	{
		int t=a[i];
		for(int j=0;j<cur.size();j++) 
			t=(t+mod-1ll*a[i-j-1]*cur[j]%mod)%mod;
		if(t==0) 
			continue;
		if(cur.empty()) 
		{
			cur.resize(i+1);
			f=i;
			dt=t;
			continue;
		}
		int p=1ll*t*qp(dt,mod-2)%mod;
		vector<int>nx(i-f-1);
		nx.push_back(p);
		for(int j=0;j<ls.size();j++) 
			nx.push_back(1ll*(mod-p)*ls[j]%mod);
		if(nx.size()<cur.size()) 
			nx.resize(cur.size());
		for(int j=0;j<cur.size();j++) 
			nx[j]=(nx[j]+cur[j])%mod;
		if(i-f+(int)ls.size()>=(int)cur.size()) 
			ls=cur,f=i,dt=t;
		cur=nx;
	}
	return cur;
}
inline void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
using poly=vector<int>;
poly mul(poly a,poly b)
{
	int n=a.size(),m=b.size();
	vector<int>c(n+m-1,0);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			add(c[i+j],a[i]*b[j]%mod);
	return c;
}
poly md(poly a,poly &b)
{
	int n=a.size(),m=b.size();
	for(int i=n-1;i>=m-1;i--)
	{
		for(int j=1;j<m;j++)
			a[i-j]=(a[i-j]+1ll*a[i]*b[j]%mod)%mod;
	}
	while(a.size()>m-1)
		a.pop_back();
	return a;
}
poly mdmul(poly a,poly b,poly &z)
{
	return md(mul(a,b),z);
}
poly qp(int b,poly &z)
{
	poly ans={1},a={0,1};
	while(b)
	{
		if(b&1)
			ans=mdmul(ans,a,z);
		a=mdmul(a,a,z);
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%s%d",s+1,&n);
	m=strlen(s+1);
	dp[0][1][m]=1;
	for(int i=0;i<=m*8;i++)
	{
		for(int l=1;l<=m;l++)
		{
			for(int r=l;r<=m;r++)
			{
				int v=dp[i][l][r];
				if(!v)
					continue;
				if(s[l]==s[r])
				{
					if(r-l<=1)
					{
						add(g[i+1],v);
						add(dp[i+1][l][r],25*v%mod);
					}
					else
					{
						add(dp[i+1][l+1][r-1],v);
						add(dp[i+1][l][r],25*v%mod);
					}
				}
				else
				{
					add(dp[i+1][l+1][r],v);
					add(dp[i+1][l][r-1],v);
					add(dp[i+1][l][r],24*v%mod);
				}
			}
		}
	}
	for(int i=0;i<=m*8;i++)
		add(g[i+1],26*g[i]%mod);
	int p=(n+m)/2;
	vector<int>f;
	for(int i=0;i<=m*8;i++)
	{
		int v;
		if(i&1)
		{
			v=26*g[i/2]%mod;
			for(int j=1;j<=m;j++)
				add(v,dp[i/2][j][j]);
		}
		else
			v=g[i/2];
		if((i&1)==((n+m)&1))
			f.push_back(v);
	}
	auto z=BM(f,mod);
	z.insert(z.begin(),0);
	poly tr=qp(p,z);
	for(int i=0;i<tr.size();i++)
		add(ans,f[i]*tr[i]%mod);
	printf("%d\n",ans);
	return 0;
}