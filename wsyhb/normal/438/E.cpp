#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int qpow(int a,int n);
const int I=86583718; // I^2=-1
const int inv2I=qpow(I<<1,mod-2);
const int max_N=1<<18|5;
int inv[max_N];
struct _
{
	inline _(int R=max_N-5)
	{
		inv[1]=1;
		for(int i=2;i<=R;++i)
			inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
}_;
inline void NTT(int *f,int n,int ty);
struct Poly
{
	vector<int> v;
	int deg;
	inline Poly() {}
	inline Poly(int Deg)
	{
		deg=Deg;
		v.resize(deg+1);
	}
	inline void setD(int Deg)
	{
		deg=Deg;
		v.resize(deg+1);
	}
	inline Poly inve(int deg_goal=-1);
	inline Poly sqrt(int deg_goal=-1);
	inline void print();
	inline Poly deri();
	inline Poly inte();
	inline Poly ln(int deg_goal=-1);
	inline Poly exp(int deg_goal=-1);
	inline Poly power(long long k,int deg_goal=-1);
	inline Poly sin();
	inline Poly cos();
	inline void mul(int t)
	{
		for(int i=0;i<=deg;++i)
			v[i]=1ll*v[i]*t%mod;
	}
	inline Poly asin();
	inline Poly atan();
	inline void rev()
	{
		reverse(v.begin(),v.end());	
	}
	inline Poly squa();
};
inline Poly operator + (const Poly &f,const Poly &g);
inline Poly operator - (const Poly &f,const Poly &g);
inline Poly operator * (const Poly &f,const Poly &g);
inline Poly operator / (const Poly &f,const Poly &g);
typedef pair<Poly,Poly> P;
inline P operator % (const Poly &f,const Poly &g);
inline Poly operator * (int coef,Poly f)
{
	for(int i=0;i<=f.deg;++i)
		f.v[i]=1ll*f.v[i]*coef%mod;
	return f;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Poly F(1e5);
	int R=0;
	for(int i=1;i<=n;++i)
	{
		int c;
		scanf("%d",&c);
		F.v[c]=1;
		R=max(R,c);
	}
	F.setD(R);
	Poly now=(mod-4)*F;
	++now.v[0],now.v[0]-=now.v[0]>=mod?mod:0;
	now=now.sqrt(m);
	++now.v[0],now.v[0]-=now.v[0]>=mod?mod:0;
	now=now.inve(m);
	for(int i=1;i<=m;++i)
	{
		int ans=now.v[i]<<1;
		ans-=ans>=mod?mod:0;
		printf("%d\n",ans);
	}
	return 0;
}
inline Poly Poly::squa()
{
	int N=1;
	while(N<=2*deg)
		N<<=1;
	static int X[max_N];
	for(int i=0;i<N;++i)
		X[i]=0;
	for(int i=0;i<=deg;++i)
		X[i]=v[i];
	NTT(X,N,1);
	for(int i=0;i<N;++i)
		X[i]=1ll*X[i]*X[i]%mod;
	NTT(X,N,-1);
	Poly res(2*deg);
	for(int i=0;i<=res.deg;++i)
		res.v[i]=X[i];
	return res;
}
inline P operator % (const Poly &f,const Poly &g)
{
	int n=f.deg,m=g.deg;
	if(n<m)
		return P(f,Poly(0));
	Poly F=f,G=g;
	F.rev(),G.rev();
	F.setD(n-m);
	Poly Q=F*G.inve(n-m);
	Q.setD(n-m);
	Q.rev();
	return P(f-g*Q,Q);
}
inline Poly operator / (const Poly &f,const Poly &g)
{
	int n=f.deg,m=g.deg;
	if(n<m)
		return Poly(0);
	Poly F=f,G=g;
	F.rev(),G.rev();
	F.setD(n-m);
	Poly Q=F*G.inve(n-m);
	Q.setD(n-m);
	Q.rev();
	return Q;
}
inline Poly Poly::asin()
{
	Poly res=squa();
	res.setD(deg);
	for(int i=0;i<=deg;++i)
		res.v[i]=res.v[i]?mod-res.v[i]:0;
	++res.v[0];
	res.v[0]-=res.v[0]>=mod?mod:0;
	res=deri()*res.sqrt().inve();
	res.setD(deg);
	res=res.inte();
	res.setD(deg);
	return res;
}
inline Poly Poly::atan()
{
	Poly res=squa();
	res.setD(deg);
	++res.v[0];
	res.v[0]-=res.v[0]>=mod?mod:0;
	res=deri()*res.inve();
	res.setD(deg);
	res=res.inte();
	res.setD(deg);
	return res;
}
inline Poly Poly::sin()
{
	Poly F=*this;
	F.mul(I);
	F=F.exp();
	F=F-F.inve();
	F.mul(inv2I);
	return F;
}
inline Poly Poly::cos()
{
	Poly F=*this;
	F.mul(I);
	F=F.exp();
	F=F+F.inve();
	for(int i=0;i<=deg;++i)
	{
		F.v[i]+=F.v[i]&1?mod:0;
		F.v[i]>>=1;
	}
	return F;
}
inline Poly Poly::power(long long k,int deg_goal)
{
	if(deg_goal==-1)
		deg_goal=deg;
	int coef=-1,ind=-1;
	for(int i=0;i<=deg;++i)
	{
		if(v[i])
		{
			coef=v[i],ind=i;
			break;
		}
	}
	if(ind==-1||min(k,deg_goal+1ll)*ind>deg_goal)
		return Poly(deg_goal);
	Poly F(deg-ind);
	int t=qpow(coef,mod-2);
	for(int i=0;i<=F.deg;++i)
		F.v[i]=1ll*v[i+ind]*t%mod;
	F=F.ln(deg_goal);
	F.mul(k%mod);
	F=F.exp(deg_goal);
	int delta=k*ind;
	t=qpow(coef,k%(mod-1));
	for(int i=deg_goal;i>=delta;--i)
		F.v[i]=1ll*F.v[i-delta]*t%mod;
	for(int i=0;i<=delta-1;++i)
		F.v[i]=0;
	return F;
}
inline Poly Poly::exp(int deg_goal)
{
	if(deg_goal==-1)
		deg_goal=deg;
	assert(v[0]==0);
	Poly res(0);
	res.v[0]=1;
	static int X[max_N],Y[max_N];
	while(res.deg<deg_goal)
	{
		int N=1;
		while(N<=3*res.deg+1)
			N<<=1;
		for(int i=0;i<N;++i)
			X[i]=Y[i]=0;
		Poly now=res.ln(res.deg<<1|1);
		for(int i=0;i<=res.deg;++i)
			X[i]=res.v[i];
		for(int i=0;i<=now.deg;++i)
		{
			Y[i]=(i<=deg?v[i]:0)-now.v[i];
			Y[i]+=Y[i]<0?mod:0;
		}
		++Y[0];
		Y[0]-=Y[0]>=mod?mod:0;
		NTT(X,N,1),NTT(Y,N,1);
		for(int i=0;i<N;++i)
			X[i]=1ll*X[i]*Y[i]%mod;
		NTT(X,N,-1);
		res=Poly(res.deg<<1|1);
		for(int i=0;i<=res.deg;++i)
			res.v[i]=X[i];
	}
	res.setD(deg_goal);
	return res;
}
inline Poly Poly::ln(int deg_goal)
{
	if(deg_goal==-1)
		deg_goal=deg;
	assert(v[0]==1);
	Poly F=deri(),G=inve(deg_goal);
	static int X[max_N],Y[max_N];
	int N=1;
	while(N<=F.deg+G.deg)
		N<<=1;
	for(int i=0;i<N;++i)
		X[i]=Y[i]=0;
	for(int i=0;i<=F.deg;++i)
		X[i]=F.v[i];
	for(int i=0;i<=G.deg;++i)
		Y[i]=G.v[i];
	NTT(X,N,1),NTT(Y,N,1);
	for(int i=0;i<N;++i)
		X[i]=1ll*X[i]*Y[i]%mod;
	NTT(X,N,-1);
	Poly res(deg_goal);
	for(int i=0;i<=deg_goal;++i)
		res.v[i]=X[i];
	res=res.inte();
	res.setD(deg_goal);
	return res;
}
inline Poly Poly::deri()
{
	Poly res(deg-1);
	for(int i=0;i<=deg-1;++i)
		res.v[i]=v[i+1]*(i+1ll)%mod;
	return res;
}
inline Poly Poly::inte()
{
	Poly res(deg+1);
	for(int i=1;i<=deg+1;++i)
		res.v[i]=1ll*v[i-1]*inv[i]%mod;
	return res;
}
inline int qpow(int a,int n)
{
	int res=1;
	while(n>0)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
int W[max_N],rev[max_N],N;
inline void NTT(int *f,int n,int ty)
{
	if(n!=N)
	{
		N=n;
		for(int i=0;i<N;++i)
			rev[i]=(rev[i>>1]>>1)|(i&1?N>>1:0);
	}
	for(int i=0;i<N;++i)
	{
		if(i<rev[i])
			swap(f[i],f[rev[i]]);
	}
	W[0]=1;
	for(int a=1,b=2;a<N;a<<=1,b<<=1)
	{
		int w=qpow(3,(mod-1)+ty*(mod-1)/b);
		for(int i=a-2;i>=0;i-=2)
			W[i+1]=1ll*(W[i]=W[i>>1])*w%mod;
		for(int i=0;i<N;i+=b)
			for(int j=i;j<i+a;++j)
			{
				int x=f[j],y=1ll*f[j+a]*W[j-i]%mod;
				f[j]=x+y,f[j]-=f[j]>=mod?mod:0;
				f[j+a]=x-y,f[j+a]+=f[j+a]<0?mod:0;
			}
	}
	if(ty==-1)
	{
		int t=qpow(N,mod-2);
		for(int i=0;i<N;++i)
			f[i]=1ll*f[i]*t%mod;
	}
}
inline Poly Poly::inve(int deg_goal)
{
	if(deg_goal==-1)
		deg_goal=deg;
	assert(v[0]);
	Poly res(0);
	res.v[0]=qpow(v[0],mod-2);
	static int X[max_N],Y[max_N];
	while(res.deg<deg_goal)
	{
		int deg_now=min(res.deg<<1|1,deg);
		int N=1;
		while(N<=deg_now+2*res.deg)
			N<<=1;
		for(int i=0;i<N;++i)
			X[i]=Y[i]=0;
		for(int i=0;i<=deg_now;++i)
			X[i]=v[i];
		for(int i=0;i<=res.deg;++i)
			Y[i]=res.v[i];
		NTT(X,N,1),NTT(Y,N,1);
		for(int i=0;i<N;++i)
			X[i]=(2+1ll*(mod-X[i])*Y[i]%mod)*Y[i]%mod;
		NTT(X,N,-1);
		res=Poly(res.deg<<1|1);
		for(int i=0;i<=min(res.deg,N-1);++i)
			res.v[i]=X[i];
		for(int i=N;i<=res.deg;++i)
			res.v[i]=0;
	}
	res.setD(deg_goal);
	return res;
}
namespace Cipolla
{
	#define p mod
	int b,S;
	struct Complex
	{
		int re,im;
		inline Complex(int Re,int Im)
		{
			re=Re,im=Im;
		}
	};
	inline Complex operator * (const Complex &a,const Complex &b)
	{
		return Complex((1ll*a.re*b.re+1ll*a.im*b.im%p*S)%p,(1ll*a.re*b.im+1ll*a.im*b.re)%p);
	}
	inline int calc(int N)
	{
		assert(qpow(N,(p-1)/2)!=p-1);
		random_device rd;
		do
		{
			b=rd()%p;
			b+=b<0?p:0;
			S=(1ll*b*b-N+p)%p;
		}while(qpow(S,(p-1)>>1)!=p-1);
		Complex A(b,1),res(1,0);
		int T=(p+1)>>1;
		while(T>0)
		{
			if(T&1)
				res=res*A;
			A=A*A;
			T>>=1;
		}
		return min(res.re,p-res.re);
	}
	#undef p
}
inline Poly Poly::sqrt(int deg_goal)
{
	if(deg_goal==-1)
		deg_goal=deg;
	Poly res(0);
	res.v[0]=Cipolla::calc(v[0]);
	static int X[max_N],Y[max_N];
	while(res.deg<deg_goal)
	{
		int deg_now=min(res.deg<<1|1,deg);
		int N=1;
		while(N<=4*res.deg+2)
			N<<=1;
		for(int i=0;i<N;++i)
			X[i]=Y[i]=0;
		for(int i=0;i<=deg_now;++i)
			X[i]=v[i];
		for(int i=0;i<=res.deg;++i)
			Y[i]=res.v[i];
		NTT(X,N,1),NTT(Y,N,1);
		for(int i=0;i<N;++i)
			X[i]=(1ll*Y[i]*Y[i]+X[i])%mod;
		Poly now=res.inve(res.deg<<1|1);
		for(int i=0;i<N;++i)
			Y[i]=0;
		for(int i=0;i<=now.deg;++i)
			Y[i]=now.v[i];
		NTT(Y,N,1);
		for(int i=0;i<N;++i)
		{
			X[i]=1ll*X[i]*Y[i]%mod;
			X[i]+=X[i]&1?mod:0;
			X[i]>>=1;
		}
		NTT(X,N,-1);
		res=Poly(res.deg<<1|1);
		for(int i=0;i<=res.deg;++i)
			res.v[i]=X[i];
	}
	res.setD(deg_goal);
	return res;
}
inline Poly operator + (const Poly &f,const Poly &g)
{
	Poly res(max(f.deg,g.deg));
	for(int i=0;i<=f.deg;++i)
		res.v[i]=f.v[i];
	for(int i=0;i<=g.deg;++i)
	{
		res.v[i]+=g.v[i];
		res.v[i]-=res.v[i]>=mod?mod:0;
	}
	while(res.deg>0&&!res.v[res.deg])
		--res.deg;
	res.v.resize(res.deg+1);
	return res;
}
inline Poly operator - (const Poly &f,const Poly &g)
{
	Poly res(max(f.deg,g.deg));
	for(int i=0;i<=f.deg;++i)
		res.v[i]=f.v[i];
	for(int i=0;i<=g.deg;++i)
	{
		res.v[i]-=g.v[i];
		res.v[i]+=res.v[i]<0?mod:0;
	}
	while(res.deg>0&&!res.v[res.deg])
		--res.deg;
	res.v.resize(res.deg+1);
	return res;
}
inline Poly operator * (const Poly &f,const Poly &g)
{
	if((f.deg==0&&f.v[0]==0)||(g.deg==0&&g.v[0]==0))
		return Poly(0);
	int N=1;
	while(N<=f.deg+g.deg)
		N<<=1;
	static int X[max_N],Y[max_N];
	for(int i=0;i<N;++i)
		X[i]=Y[i]=0;
	for(int i=0;i<=f.deg;++i)
		X[i]=f.v[i];
	for(int i=0;i<=g.deg;++i)
		Y[i]=g.v[i];
	NTT(X,N,1),NTT(Y,N,1);
	for(int i=0;i<N;++i)
		X[i]=1ll*X[i]*Y[i]%mod;
	NTT(X,N,-1);
	Poly res(f.deg+g.deg);
	for(int i=0;i<=res.deg;++i)
		res.v[i]=X[i];
	return res;
}
inline void Poly::print()
{
	bool flag=false;
	for(int i=deg;i>=2;--i)
	{
		if(v[i])
		{
			if(v[i]==1)
				fprintf(stderr,"%sx^%d",flag?"+":"",i);
			else
				fprintf(stderr,"%s%dx^%d",flag?"+":"",v[i],i);
			flag=true;
		}
	}
	if(deg>=1&&v[1])
	{
		if(v[1]==1)
			fprintf(stderr,"%sx",flag?"+":"");
		else
			fprintf(stderr,"%s%dx",flag?"+":"",v[1]);
		flag=true;
	}
	if(!flag)
		fprintf(stderr,"%d\n",v[0]);
	else if(v[0])
		fprintf(stderr,"+%d\n",v[0]);
}