#include<bits/stdc++.h>
using namespace std;
const int N=300005,mod=998244353;
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
vector<int>rev(vector<int>a)
{
	a[0]=1;
	for(int i=1;i<a.size();i++)
		a[i]=(mod-a[i])%mod;
	return a;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	vector<int>a(n+1),b(n+1);
	int h=1;
	for(int i=1;i<=n;i++)
	{
		int t=(m+i)/2;
		if((m+i)&1)
			h=1ll*h*(t-i+1)%mod;
		else
			h=1ll*h*t%mod;
		h=1ll*h*qp(i,mod-2)%mod;
		if(i&1)
			b[i]=(((i/2)&1?-1:1)*h+mod)%mod;
		else
			a[i]=(((i/2)&1?1:-1)*h+mod)%mod;
	}
	a=rev(a);
	auto c=mul(b,inv(a));
	c=rev(c);
	auto f=ln(inv(a)),g=ln(inv(c));
	int ans=1ll*n*(f[n]+g[n])%mod;
	printf("%d\n",ans);
	return 0;	
}