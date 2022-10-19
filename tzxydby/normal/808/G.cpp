#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int rv[N<<2],w[N<<2];
void ntt(int *a,int n,int f)
{
	for(int i=0;i<n;i++)
		rv[i]=(rv[i>>1]>>1)|((i&1)*(n>>1));
	int wn=qp(f?(mod+1)/3:3,(mod-1)/n);
	w[0]=1;
	for(int i=1;i<n;i++)
		w[i]=1ll*w[i-1]*wn%mod;
	for(int i=0;i<n;i++)
		if(i<rv[i])
			swap(a[i],a[rv[i]]);
	for(int mid=1;mid<n;mid<<=1)
	{
		for(int i=0;i<n;i+=(mid<<1))
		{
			for(int j=0;j<mid;j++)
			{
				int x=a[i+j],y=1ll*a[i+j+mid]*w[n/(mid<<1)*j]%mod;
				a[i+j]=(x+y>=mod?x+y-mod:x+y);
				a[i+j+mid]=(x-y<0?x-y+mod:x-y);
			}
		}
	}
	if(f)
	{
		int iv=qp(n,mod-2);
		for(int i=0;i<n;i++)
			a[i]=1ll*a[i]*iv%mod;
	}
}
int n,m,x[N<<2],x2[N<<2],x3[N<<2],y[N<<2],y2[N<<2],z[N<<2],a[N],p[N],sz,hv[N],vis[N];
vector<int>b,sq,d;
pair<int,int>dp[N],f[N],g[N][100],ans;
char s[N],t[N],st[N];
int main()
{
	scanf("%s%s",s,t);
	n=strlen(s),m=strlen(t);
	sz=1;
	while(sz<=n+m+5)
		sz<<=1;
	for(int i=0;i<n;i++)
		x[i]=(s[i]=='?'?0:s[i]);
	for(int i=0;i<m;i++)
		y[m-i]=t[i],z[m-i]=1;
	for(int i=0;i<sz;i++)
	{
		x2[i]=1ll*x[i]*x[i]%mod;
		x3[i]=1ll*x2[i]*x[i]%mod;
		y2[i]=1ll*y[i]*y[i]%mod;
	}
	ntt(x,sz,0),ntt(x2,sz,0),ntt(x3,sz,0),ntt(y,sz,0),ntt(y2,sz,0),ntt(z,sz,0);
	for(int i=0;i<sz;i++)
		z[i]=(1ll*x3[i]*z[i]%mod+mod-2ll*x2[i]*y[i]%mod+1ll*x[i]*y2[i]%mod)%mod;
	ntt(z,sz,1);
	for(int i=m;i<=n;i++)
		if(!z[i])
			a[i]=1;
	for(int i=1,j=0;i<m;i++)
	{
		while(j&&t[i]!=t[j])
			j=p[j-1];
		if(t[i]==t[j])
			j++;
		p[i]=j;
	}
	for(int i=p[m-1]-1;i!=-1;i=p[i]-1)
		b.push_back(m-i-1);
	sort(b.begin(),b.end());
	for(int i=0;i<b.size();i++)
		if(i>=2&&b[i]-b[i-1]==b[i-1]-b[i-2])
			vis[i]=vis[i-1]=1;
	for(int i=0;i<b.size();i++)
		if(!vis[i])
			sq.push_back(b[i]),d.push_back((i+1==b.size()?0:b[i+1]-b[i]));
	for(int i=1;i<=n;i++)
	{
		pair<int,int>v={0,0};
		if(a[i])
		{
			dp[i]=f[i-m];
			for(int j=0;j<sq.size();j++)
				if(i>sq[j])
					dp[i]=max(dp[i],g[i-sq[j]][j]);
			dp[i].first++;
			v={dp[i].first,i};
		}
		ans=max(ans,v);
		f[i]=max(f[i-1],v);
		for(int j=0;j<sq.size();j++)
		{
			g[i][j]=v;
			if(i>d[j])
				g[i][j]=max(g[i][j],g[i-d[j]][j]);
		}
	}
	printf("%d\n",ans.first);
	return 0;
}