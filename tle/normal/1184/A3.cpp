//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int mod;
const int FFTpsz=1<<19;
const int FFTmx=FFTpsz+233;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int FFTsz;
const double pi=acos(-1);
struct point
{
	double x,y;
	point(double X=0,double Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point operator*(const double &t)const{return point(x*t,y*t);}
	point conj()const{return point(x,-y);}
};
point w_pre[FFTmx];
int uptopow(int n)
{
	int ret=1;
	while(ret<n)ret<<=1;
	return ret;
}
void FFTprecalc()
{
	for(int i=0;i<=FFTpsz;i++)w_pre[i]=point(cos(2*pi/FFTpsz*i),sin(2*pi/FFTpsz*i));
}
void FFTinit(int n)
{
	FFTsz=uptopow(n);
}
void FFT(point a[],int coef)
{
	for(int i=0,j=0;i<FFTsz;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=FFTsz>>1;(j^=t)<t;t>>=1);
	}
	static point w[FFTmx];
	for(int l=1;l<FFTsz;l<<=1)
	{
		int l2=l<<1;
		if(coef==1)for(int j=0;j<l;j++)w[j]=w_pre[FFTpsz/l2*j];
		else for(int j=0;j<l;j++)w[j]=w_pre[FFTpsz-FFTpsz/l2*j];
		for(int i=0;i<FFTsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+j+l]*w[j];
				a[i+j+l]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*(1.0/FFTsz);
	}
}
void FFT2(point a[],point b[],int coef)
{
	static point A[FFTmx];
	if(coef==1)
	{
		for(int i=0;i<FFTsz;i++)A[i]=point(a[i].x,b[i].x);
		FFT(A,1);
		A[FFTsz]=A[0];
		for(int i=0;i<FFTsz;i++)
		{
			a[i]=(A[i]+A[FFTsz-i].conj())*point(0.5,0);
			b[i]=(A[i]-A[FFTsz-i].conj())*point(0,-0.5);
		}
	}
	else
	{
		for(int i=0;i<FFTsz;i++)A[i]=a[i]+b[i]*point(0,1);
		FFT(A,-1);
		for(int i=0;i<FFTsz;i++)a[i]=point(A[i].x,0),b[i]=point(A[i].y,0);
	}
}
void polymul(int a[],int an,int b[],int bn,int c[],int cn,int md)
{
	mod=md;
	if(1ll*an*bn<10000)
	{
		static int mul_t[FFTmx];
		for(int i=0;i<cn;i++)mul_t[i]=0;
		for(int i=0;i<an;i++)
		{
			for(int j=0;j<bn&&i+j<cn;j++)
			{
				mul_t[i+j]=(mul_t[i+j]+1ll*a[i]*b[j])%mod;
			}
		}
		for(int i=0;i<cn;i++)c[i]=(mul_t[i]%mod+mod)%mod;
		return;
	}
	static point mul_a0[FFTmx],mul_a1[FFTmx];
	static point mul_b0[FFTmx],mul_b1[FFTmx];
	FFTinit(an+bn);
	for(int i=0;i<FFTsz;i++)mul_a0[i]=point(i<an?((a[i]%mod+mod)%mod)&32767:0,0);
	for(int i=0;i<FFTsz;i++)mul_a1[i]=point(i<an?((a[i]%mod+mod)%mod)>>15:0,0);
	for(int i=0;i<FFTsz;i++)mul_b0[i]=point(i<bn?((b[i]%mod+mod)%mod)&32767:0,0);
	for(int i=0;i<FFTsz;i++)mul_b1[i]=point(i<bn?((b[i]%mod+mod)%mod)>>15:0,0);	
	FFT2(mul_a0,mul_a1,1);
	FFT2(mul_b0,mul_b1,1);
	for(int i=0;i<FFTsz;i++)
	{
		point t0=mul_a0[i]*mul_b0[i];
		point t1=mul_a0[i]*mul_b1[i]+mul_a1[i]*mul_b0[i];
		point t2=mul_a1[i]*mul_b1[i];
		mul_a0[i]=t0;
		mul_a1[i]=t1;
		mul_b0[i]=t2;
	}
	FFT2(mul_a0,mul_a1,-1);
	FFT(mul_b0,-1);
	for(int i=0;i<cn;i++)
	{
		if(i<FFTsz)
		{
			ll t0=ll(mul_a0[i].x+0.5)%mod;
			ll t1=ll(mul_a1[i].x+0.5)%mod;
			ll t2=ll(mul_b0[i].x+0.5)%mod; 
			c[i]=((t0+(t1<<15)+(t2<<30))%mod+mod)%mod;
		}
		else c[i]=0;
	}
}
void CZT(int a[],int N,int w,int md,int coef)//here w should be the sqrt of original w  md should be prime
{
	mod=md;
	if(coef==-1)w=qpow(w,mod-2);
	static int CZT_f[FFTmx],CZT_g[FFTmx],CZT_a[FFTmx];
	for(int i=0;i<N;i++)CZT_f[i]=1ll*a[i]%mod*qpow(w,1ll*i*i%(mod-1))%mod;
	for(int i=0;i<N+N;i++)CZT_g[i]=qpow(w,mod-1-1ll*(N-i)*(N-i)%(mod-1))%mod;
	polymul(CZT_f,N,CZT_g,N+N,CZT_a,N+N,mod);
	for(int i=0;i<N;i++)a[i]=1ll*qpow(w,1ll*i*i%(mod-1))*(CZT_a[i+N])%mod;
	if(coef==-1)
	{
		ll inv=qpow(N,mod-2);
		for(int i=0;i<N;i++)a[i]=a[i]*inv%mod;
	}
}
bool isp(int x)
{
	for(int i=2;1ll*i*i<=x;i++)if(x%i==0)return false;
	return true;
}
int calc_g(int md)
{
	for(int pr=2;pr<md;pr++)
	{
		bool ok=1;
		for(int j=2;j<=md-1;j++)
		{
			j=(md-1)/((md-1)/j);
			if((md-1)%j==0)
			{
				if(qpow(pr,(md-1)/j)==1)
				{
					ok=0;
					break;
				}
			}
		}
		if(ok)return pr;
	}
	assert(false);
}

const int maxn = 100111;
int n, m;
char s[maxn];
char t[maxn];
int A[FFTmx], a[FFTmx];
int calchs(char s[], int r)
{
	int ret = 0;
	int t = 1;
	for (int i=0; i<n; i++)
	{
		ret = (ret+1ll*t*s[i])%mod;
		t = 1ll*t*r%mod;
	}
	return ret;
}
int main()
{
	FFTprecalc();
	scanf("%d%d", &n, &m);
	mod = 200000;
	scanf("%s", s);
	scanf("%s", t);
	for (int i=0; i<n; i++) A[i] += s[i];
	for (int i=0; i<n; i++) A[i] -= t[i];
	while (true)
	{
		if (isp(mod))
		{
			int g = calc_g(mod);
			int N = (mod-1)/2;
			for (int i=0; i<N; i++) a[i] = A[i];
			CZT(a, N, g, mod, 1);
			int cur = 1;
//			cerr<<"mod="<<mod<<" g="<<g<<endl;
			for (int i=0; i<N; i++)
			{
				if (a[i]%mod==0&&cur>=2&&cur<=mod-2)
				{
					cout<<mod<<" "<<cur<<endl;
					assert((calchs(s, cur)-calchs(t, cur))%mod==0);
					return 0;
				}
				cur = 1ll*cur*g%mod*g%mod;
			}
		}
		mod++;
	}
	return 0;
}