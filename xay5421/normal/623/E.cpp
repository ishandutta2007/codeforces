// author: xay5421
// created: Wed Mar 10 15:32:18 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const long double PI=acos(-1);
const int N=100005,P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
struct cp{
	double x,y;
	cp operator+(const cp&k2)const{return(cp){x+k2.x,y+k2.y};}
	cp operator-(const cp&k2)const{return(cp){x-k2.x,y-k2.y};}
	cp operator*(const cp&k2)const{return(cp){x*k2.x-y*k2.y,x*k2.y+y*k2.x};}
	cp conj(){return(cp){x,-y};}
}w[N*2];
void fft(cp*a,int lim){
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=(lim>>1);(j^=k)<k;k>>=1);
	}
	for(int i=1;i<lim;i<<=1){
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				cp x=a[j+k],y=w[i+k]*a[i+j+k];
				a[j+k]=x+y,a[i+j+k]=x-y;
			}
		}
	}
}
vector<int>pmul(const vector<int>&a,const vector<int>&b){
	static cp A[N*2],B[N*2],dfta[N*2],dftb[N*2],dftc[N*2],dftd[N*2];
	int need=SZ(a)+SZ(b)-1;
	int lim=1;while(lim<=need)lim<<=1;
	for(int j=lim>>1;j<lim;++j)w[j]=(cp){(double)cos(PI*2*(j-(lim>>1))/lim),(double)sin(PI*2*(j-(lim>>1))/lim)};
	for(int j=(lim>>1)-1;j>=0;--j)w[j]=w[j<<1];
	rep(i,0,SZ(a)-1)A[i]=(cp){double(a[i]&32767),double(a[i]>>15)};
	rep(i,SZ(a),lim-1)A[i]=(cp){0.,0.};
	rep(i,0,SZ(b)-1)B[i]=(cp){double(b[i]&32767),double(b[i]>>15)};
	rep(i,SZ(b),lim-1)B[i]=(cp){0.,0.};
	fft(A,lim),fft(B,lim);
	rep(i,0,lim-1){
		int j=(lim-i)&(lim-1);
		static cp da,db,dc,dd;
		da=(A[i]+A[j].conj())*(cp){0.5,0.};
		db=(A[i]-A[j].conj())*(cp){0.,-0.5};
		dc=(B[i]+B[j].conj())*(cp){0.5,0};
		dd=(B[i]-B[j].conj())*(cp){0.,-0.5};
		dfta[j]=da*dc;
		dftb[j]=da*dd;
		dftc[j]=db*dc;
		dftd[j]=db*dd;
	}
	rep(i,0,lim-1)A[i]=dfta[i]+dftb[i]*(cp){0.,1.};
	rep(i,0,lim-1)B[i]=dftc[i]+dftd[i]*(cp){0.,1.};
	fft(A,lim),fft(B,lim);
	vector<int>c(need);
	rep(i,0,need-1){
		int da=(LL)(A[i].x/lim+0.5)%P;
		int db=(LL)(A[i].y/lim+0.5)%P;
		int dc=(LL)(B[i].x/lim+0.5)%P;
		int dd=(LL)(B[i].y/lim+0.5)%P;
		c[i]=(da+((LL)(db+dc)<<15)+((LL)dd<<30))%P;
	}
	return c;
}
vector<int>operator*(const vector<int>&a,const vector<int>&b){
	if(SZ(a)<=100&&SZ(b)<=100){
		vector<int>c(SZ(a)+SZ(b)-1);
		rep(i,0,SZ(a)-1)rep(j,0,SZ(b)-1)uad(c[i+j],mu(a[i],b[j]));
		return c;
	}
	return pmul(a,b);
}
LL n;
int K,fac[N],inv[N],ifac[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
vector<int>solve(LL n){
	if(n==1){
		vector<int>res(K+1,1);
		res[0]=0;
		return res;
	}
	vector<int>z=solve(n/2);
	vector<int>f1(z);
	rep(i,0,SZ(f1)-1)f1[i]=mu(f1[i],ifac[i]);
	vector<int>f2(f1);
	rep(i,0,SZ(f2)-1)f2[i]=mu(f2[i],po(2,(n/2)%(P-1)*i%(P-1)));
	vector<int>f3(f1*f2);
	f3.resize(K+1);
	rep(i,0,SZ(f3)-1)f3[i]=mu(f3[i],fac[i]);
	if(n&1){
		vector<int>f4(ifac,ifac+K+1);
		f4[0]=0;
		rep(i,0,SZ(f3)-1)f3[i]=mu(f3[i],ifac[i],po(2,i));
		f3=f3*f4;
		f3.resize(K+1);
		rep(i,0,SZ(f3)-1)f3[i]=mu(f3[i],fac[i]);
	}
	return f3;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%lld%d",&n,&K);
	if(n>K)puts("0"),exit(0);
	vector<int>res=solve(n);
	int ans=0;
	rep(i,0,K){
		uad(ans,mu(C(K,i),res[i]));
	}
	printf("%d\n",ans);
	return 0;
}