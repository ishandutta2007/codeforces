#include<bits/stdc++.h>
using namespace std;
const int N=1100005,mod=998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int rv[N],w[N],fc[N];
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
int n,d[N],ans;
vector<int>e[N],tr[N<<2];
void dfs(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		d[u]++;
		dfs(v,u);
	}
}
void sol(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]={1,d[l]};
		return;
	}
	int mid=l+r>>1;
	sol(k<<1,l,mid);
	sol(k<<1|1,mid+1,r);
	tr[k]=mul(tr[k<<1],tr[k<<1|1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	fc[0]=1;
	for(int i=1;i<=n;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	sol(1,1,n);
	for(int i=0;i<=n;i++)
	{
		int v=1ll*fc[n-i]*tr[1][i]%mod;
		if(i&1)
			v=(mod-v)%mod;
		ans=(ans+v)%mod;
	}
	printf("%d\n",ans);
	return 0;
}