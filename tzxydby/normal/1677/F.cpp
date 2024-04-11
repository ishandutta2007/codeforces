#include<bits/stdc++.h>
using namespace std;
const int N=300005,mod=998244353,mx=100000;
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
vector<int>qd(vector<int>a)
{
	int n=a.size();
	for(int i=1;i<n;i++)
		a[i-1]=1ll*a[i]*i%mod;
	a.pop_back();
	return a;
}
vector<int>jf(vector<int>a)
{
	int n=a.size();
	a.push_back(0);
	for(int i=n;i>=1;i--)
		a[i]=1ll*a[i-1]*qp(i,mod-2)%mod;
	a[0]=0;
	return a;
}
vector<int>ln(vector<int>a)
{
	a=mul(qd(a),inv(a));
	return jf(a);
}
vector<int>ex(vector<int>a)
{
	int n=a.size();
	if(n==1)
	{
		a[0]=1;
		return a;
	}
	int m=1;
	while(m<(n<<1))
		m<<=1;
	vector<int>a0=a;
	a0.resize((n+1)/2);
	vector<int>b0=ex(a0);
	vector<int>b=b0;
	b.resize(n);
	b=ln(b);
	a.resize(m),b0.resize(m),b.resize(m);
	ntt(a,0),ntt(b0,0),ntt(b,0);
	for(int i=0;i<m;i++)
		a[i]=1ll*b0[i]*(a[i]-b[i]+mod+1)%mod;
	ntt(a,1);
	a.resize(n);
	return a;
}
vector<int>smul(vector<int>a,vector<int>b)
{
	vector<int>c(min(a.size(),b.size()));
	for(int i=0;i<c.size();i++)
		c[i]=1ll*a[i]*b[i]%mod;
	return c;
}
vector<int>rev(vector<int>a)
{
	reverse(a.begin(),a.end());
	return a;
}
vector<int>div(vector<int>a,vector<int>b)
{
	int n=a.size(),m=b.size();
	a=rev(a),b=rev(b);
	a.resize(n-m+1),b.resize(n-m+1);
	a=mul(a,inv(b));
	a.resize(n-m+1);
	return rev(a);
}
vector<int>md(vector<int>a,vector<int>b)
{
	int n=a.size(),m=b.size();
	if(n<m)
		return a;
	vector<int>q=div(a,b);
	vector<int>w=mul(b,q);
	vector<int>r(m-1,0);
	for(int i=0;i<m-1;i++)
		r[i]=(a[i]+mod-w[i])%mod;
	return r;
}
vector<int>tr[N<<2];
int ans[N];
void build(int k,int l,int r,vector<int>&v)
{
	if(l==r)
	{
		tr[k]=vector<int>{(mod-v[l-1])%mod,1};
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid,v);
	build(k<<1|1,mid+1,r,v);
	tr[k]=mul(tr[k<<1],tr[k<<1|1]);
}
void sol(int k,int l,int r,vector<int>a)
{
	a=md(a,tr[k]);
	if(l==r)
	{
		ans[l]=a[0];
		return;
	}
	int mid=l+r>>1;
	sol(k<<1,l,mid,a);
	sol(k<<1|1,mid+1,r,a);
}
vector<int>qz(vector<int>a,vector<int>b)
{
	int m=b.size();
	build(1,1,m,b);
	sol(1,1,m,a);
	vector<int>r(m,0);
	for(int i=0;i<m;i++)
		r[i]=ans[i+1];
	return r;
}
vector<int>solc(int k,int l,int r,vector<int>&x,vector<int>&y)
{
	if(l==r)
		return vector<int>{1ll*x[l-1]*qp(y[l-1],mod-2)%mod};
	int mid=l+r>>1;
	vector<int>vl=mul(solc(k<<1,l,mid,x,y),tr[k<<1|1]);
	vector<int>vr=mul(solc(k<<1|1,mid+1,r,x,y),tr[k<<1]);
	int n=max(vl.size(),vr.size());
	vl.resize(n);
	for(int i=0;i<n;i++)
		if(i<vr.size())
			vl[i]=(vl[i]+vr[i])%mod;
	return vl;
}
vector<int>cz(vector<int>x,vector<int>y)
{
	int n=x.size();
	build(1,1,n,x);
	vector<int>g=tr[1];
	g=qd(g);
	vector<int>v=qz(g,x);
	vector<int>r=solc(1,1,n,y,v);
	return r;
}
int n,k,p,a[N],pr[N][2],sf[N][2],fc[N],iv[N],s;
vector<int>f,g,x;
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	fc[0]=iv[0]=1;
	for(int i=1;i<=mx;i++)	
		fc[i]=1ll*fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	pr[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		pr[i][0]=(1ll*pr[i-1][0]*(a[i]+1)%mod+1)%mod;
		pr[i][1]=(1ll*pr[i-1][1]*(a[i]+1)%mod+1ll*pr[i-1][0]*a[i]%mod)%mod;
	}
	sf[n+1][0]=1;
	for(int i=n;i;i--)
	{
		sf[i][0]=(1ll*sf[i+1][0]*(a[i]+1)%mod+1)%mod;
		sf[i][1]=(1ll*sf[i+1][1]*(a[i]+1)%mod+1ll*sf[i+1][0]*a[i]%mod)%mod;
	}
	f.resize(k+1),g.resize(k+1);
	for(int i=0;i<=k;i++)
		g[i]=1ll*p*iv[i]%mod;
	g[0]--;
	g=inv(g);
	for(int i=0;i<=k;i++)
		f[i]=1ll*g[k-i]*iv[i]%mod;
	for(int i=1;i<=n;i++)
		x.push_back(a[i]+1);
	x=qz(f,x);
	for(int i=1;i<=n;i++)
	{
		int c=(1ll*pr[i-1][0]*sf[i+1][1]%mod+1ll*pr[i-1][1]*sf[i+1][0]%mod+1ll*pr[i-1][0]*sf[i+1][0]%mod)%mod;
		int v=1ll*(1ll*qp(p,a[i]+1)*x[i-1]%mod+mod-g[k])%mod*fc[k]%mod;
		s=(s+1ll*c*v%mod)%mod;
	}
	printf("%d\n",s);
	return 0;	
}