#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=4000005,mod=998244353;
int n,m,k,l[N],r[N],a[N],vis[N],t,mx,b[N],fl;
vector<int>s,p;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int rv[N],w[N];
void ntt(vector<int>&a,int f)
{
	int n=a.size();
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
vector<int>mul(vector<int>a,vector<int>b)
{
	int n=1,m=a.size()+b.size()-1;
	if(a.size()*b.size()<=4096)
	{
		vector<int>c(m,0);
		for(int i=0;i<a.size();i++)
			for(int j=0;j<b.size();j++)
				c[i+j]=(c[i+j]+1ll*a[i]*b[j]%mod)%mod;
		return c;
	}
	while(n<m)
		n<<=1;
	a.resize(n),b.resize(n);
	ntt(a,0),ntt(b,0);
	for(int i=0;i<n;i++)
		a[i]=1ll*a[i]*b[i]%mod;
	ntt(a,1);
	a.resize(m);
	return a;
}
vector<int>inv(vector<int>a)
{
	int n=a.size();
	if(n==1)
	{
		a[0]=qp(a[0],mod-2);
		return a;
	}
	int m=1;
	while(m<(n<<1))
		m<<=1;
	vector<int>a0=a;
	a0.resize((n+1)/2);
	vector<int>b0=inv(a0);
	a.resize(m),b0.resize(m);
	ntt(a,0),ntt(b0,0);
	for(int i=0;i<m;i++)
		a[i]=1ll*b0[i]*(2-1ll*a[i]*b0[i]%mod+mod)%mod;
	ntt(a,1);
	a.resize(n);
	return a;
}
void dfs(int u)
{
	vis[u]=1;
	t++;
	if(!fl)
		return;
	if(!r[u])
		return;
	if(b[u]||vis[r[u]])
		b[u]=1,fl=0;
	dfs(r[u]);
	if(b[r[u]])
		b[u]=1,fl=0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
			scanf("%d",&a[j]);
		for(int j=2;j<=c;j++)
		{
			if(l[a[j]]&&l[a[j]]!=a[j-1])
				b[a[j]]=1;
			l[a[j]]=a[j-1];
		}
		for(int j=1;j<c;j++)
		{
			if(r[a[j]]&&r[a[j]]!=a[j+1])
				b[a[j]]=1;
			r[a[j]]=a[j+1];
		}
	}
	mx=m+5;
	s.resize(mx);
	for(int i=1;i<=k;i++)
	{
		if(vis[i]||b[i])
			continue;
		if(!l[i]&&!r[i])
		{
			s[1]++;
			vis[i]=1;
			continue;
		}
		if(l[i]==i&&r[i]==i)
		{
			vis[i]=b[i]=1;
			continue;
		}
		if(!l[i]&&r[i])
		{
			t=0,fl=1;
			dfs(i);
			if(fl&&t<=m)
				s[t]++;
		}
	}
	vector<int>f=vector<int>(mx,0);
	f[0]=(f[0]+mod-1)%mod;
	s[0]=(s[0]+mod-1)%mod;
	vector<int>iv=inv(s);
	iv[0]=(iv[0]+mod-1)%mod;
	f=mul(f,iv);
	printf("%d\n",f[m]);
	return 0;
}