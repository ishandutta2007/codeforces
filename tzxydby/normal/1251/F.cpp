#include<bits/stdc++.h>
using namespace std;
const int N=1100005,mod=998244353,mx=300000;
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
int n,k,q,a[N],b[N],v[N],ans[N],fc[N],iv[N];
int c(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
void sol(int w)
{
	int x=0,y=0;
	for(int i=1;i<w;i++)
	{
		if(a[i]==1)
			x++;
		if(a[i]>1)
			y+=2;
	}
	vector<int>p1(n+1,0),p2(n+1,0);
	for(int i=0;i<=x;i++)
		p1[i]=1ll*c(x,i)*qp(2,i)%mod;
	for(int i=0;i<=y;i++)
		p2[i]=c(y,i);
	vector<int>p=mul(p1,p2);
	for(int i=1;i<=q;i++)
	{
		int r=v[i]/2-1-w;
		if(r>=0&&r<p.size())
			ans[i]=(ans[i]+p[r])%mod;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=k;i++)
		scanf("%d",&b[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d",&v[i]);
	fc[0]=1;
	for(int i=1;i<=mx;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	iv[mx]=qp(fc[mx],mod-2);
	for(int i=mx-1;i>=0;i--)
		iv[i]=1ll*iv[i+1]*(i+1)%mod;
	for(int i=1;i<=k;i++)
		sol(b[i]);
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;	
}