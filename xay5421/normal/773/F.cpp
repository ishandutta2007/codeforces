// author: xay5421
// created: Mon Apr 26 09:57:55 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const long double PI=acos(-1);
int P;
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
const int N=100005;
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
vector<int>operator+(vector<int>a,vector<int>b){
	if(SZ(a)<SZ(b))swap(a,b);
	rep(i,0,SZ(b)-1)uad(a[i],b[i]);
	return a;
}
int n,lim,ans;
vector<int>F[40][2];
void sol(int cur,int lim){
	if(lim==1){
		F[cur][0].assign(n+1,0),F[cur][1].assign(n+1,0);
		F[cur][1][1]=1;
		uad(ans,1);
		return;
	}
	sol(cur+1,lim>>1);
	F[cur][0]=F[cur+1][0],F[cur][1]=F[cur+1][1];
	rep(i,0,1){
		vector<int>tmp(F[cur+1][0]+F[cur+1][1]);
		assert(tmp[0]==0);
		uad(tmp[0],1);
		vector<int>res(tmp*F[cur+1][((lim>>1)+i)&1]);
		res.resize(n+1);
		rep(j,0,n)uad(F[cur][i][j],res[j]);
	}
	if(lim&1){
		per(i,n,1){
			uad(F[cur][1][i],F[cur][0][i-1],F[cur][1][i-1]);
		}
		uad(F[cur][1][1],1);
	}
	for(int i=1;i<=n;i+=2)uad(ans,F[cur][1][i]);
}
int main(){
	scanf("%d%d%d",&n,&lim,&P);
	if(lim==1)puts("0"),exit(0);
	sol(1,lim>>1);
	printf("%d\n",ans);
	return 0;
}