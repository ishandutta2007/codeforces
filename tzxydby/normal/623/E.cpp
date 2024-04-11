#include<bits/stdc++.h>
using namespace std;
namespace mtt
{
	const int N=600005,mod=1e9+7;
	const double pi=acos(-1);
	struct com
	{
		double r,i;
		com(){}
		com(double _r,double _i):r(_r),i(_i){}
		com operator+(const com x){return {r+x.r,i+x.i};}
		com operator-(const com x){return {r-x.r,i-x.i};}
		com operator*(const com x){return {r*x.r-i*x.i,r*x.i+i*x.r};}
		com operator/(const double x){return {r/x,i/x};}
		com conj(){return {r,-i};}
	};
	int m,r[N],l;
	int a[N],b[N],x[N],y[N];
	com w[N];
	void fft(com *a)
	{
		for(int i=0;i<m;i++)
			if(i<r[i])
				swap(a[i],a[r[i]]);
		for(int i=1;i<m;i<<=1)
		{
			for(int j=0;j<m;j+=(i<<1))
			{
				for(int k=0;k<i;k++)
				{
					com x=a[j+k],y=w[m/(i<<1)*k]*a[j+k+i];
					a[j+k]=x+y;
					a[j+k+i]=x-y;
				}	
			}
		}
	}
	void cal(int *x,int *y)
	{
		com a[N],b[N],da[N],db[N],dc[N],dd[N];
		for(int i=0;i<m;i++)
		{
			a[i]=com(x[i]&32767,x[i]>>15);
			b[i]=com(y[i]&32767,y[i]>>15);
		}
		fft(a),fft(b);
		for(int i=0;i<m;i++)
		{
			int j=(m-i)&(m-1);
			com va,vb,vc,vd;
			va=(a[i]+a[j].conj())*com(0.5,0);
			vb=(a[i]-a[j].conj())*com(0,-0.5);
			vc=(b[i]+b[j].conj())*com(0.5,0);
			vd=(b[i]-b[j].conj())*com(0,-0.5);
			da[j]=va*vc;
			db[j]=va*vd;
			dc[j]=vb*vc;
			dd[j]=vb*vd;
		}
		for(int i=0;i<m;i++)
		{
			a[i]=da[i]+db[i]*com(0,1);
			b[i]=dc[i]+dd[i]*com(0,1);
		}
		fft(a),fft(b);
		for(int i=0;i<m;i++)
		{
			long long va=a[i].r/m+0.5,vb=a[i].i/m+0.5,vc=b[i].r/m+0.5,vd=b[i].i/m+0.5;
			va%=mod,vb%=mod,vc%=mod,vd%=mod;
			x[i]=(va+((vb+vc)<<15)+((vd)<<30))%mod;
		}
	}
	vector<int>mul(vector<int>a,vector<int>b)
	{
		m=1,l=0;
		int ca=a.size(),cb=b.size();
		while(m<ca+cb-1)
			m<<=1,l++;
		for(int i=0;i<m;i++)
			r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<m;i++)
			w[i]=com(cos(2*pi*i/m),sin(2*pi*i/m));
		for(int i=0;i<m;i++)
			x[i]=y[i]=0;
		for(int i=0;i<ca;i++)
			x[i]=a[i];
		for(int i=0;i<cb;i++)
			y[i]=b[i];
		cal(x,y);
		a.resize(ca+cb-1);
		for(int i=0;i<a.size();i++)
			a[i]=x[i];
		return a;
	}
}
const int N=30005,mod=1e9+7;
int n,k,fc[N],iv[N],ans;
long long rn;
vector<int>p[30];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int c(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
int main()
{
	scanf("%lld%d",&rn,&k);
	if(rn>k)
	{
		puts("0");
		return 0;
	}
	n=rn;
	fc[0]=1;
	for(int i=1;i<=k;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	iv[k]=qp(fc[k],mod-2);
	for(int i=k-1;i>=0;i--)
		iv[i]=1ll*iv[i+1]*(i+1)%mod;
	p[0].resize(k+1);
	for(int i=1;i<=k;i++)
		p[0][i]=1;
	for(int i=1;(1<<i)<=n;i++)
	{
		vector<int>p1=p[i-1],p2=p[i-1];
		for(int j=0;j<=k;j++)
			p1[j]=1ll*p1[j]*iv[j]%mod*qp(2,(1<<i-1)*j)%mod;
		for(int j=0;j<=k;j++)
			p2[j]=1ll*p2[j]*iv[j]%mod;
		p[i]=mtt::mul(p1,p2);
		p[i].resize(k+1);
		for(int j=0;j<=k;j++)
			p[i][j]=1ll*p[i][j]*fc[j]%mod;
	}
	vector<int>f;
	for(int i=0;i<=20;i++)
	{
		if(n>>i&1)
		{
			if(!f.size())
				f=p[i];
			else
			{
				auto g=p[i];
				for(int j=0;j<=k;j++)
					f[j]=1ll*f[j]*iv[j]%mod*qp(2,(1<<i)*j)%mod;
				for(int j=0;j<=k;j++)
					g[j]=1ll*g[j]*iv[j]%mod;
				f=mtt::mul(f,g);
				for(int j=0;j<=k;j++)
					f[j]=1ll*f[j]*fc[j]%mod;
			}
		}
	}
	for(int i=1;i<=k;i++)
		ans=(ans+1ll*f[i]*c(k,i)%mod)%mod;
	printf("%d\n",ans);
	return 0;
}