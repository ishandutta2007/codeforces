#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
inline int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1) ans=(1ll*ans*a)%p;
		a=(1ll*a*a)%p;
	}
	return ans;
}
inline int inverse(int a){
	return qow(a,p-2);
}
int f[110000];
int g[110000];
int h[210000];
const int C=(1<<15);
struct cp{
	double x,y;
	inline cp() {}
	inline cp(double xx,double yy) :x(xx),y(yy) {}
	inline cp operator +(const cp &b) const{return cp(x+b.x,y+b.y);}
	inline cp operator -(const cp &b) const{return cp(x-b.x,y-b.y);}
	inline cp operator *(const cp &b) const{return cp(x*b.x-y*b.y,x*b.y+y*b.x);}
	inline cp operator *(const double &b) const{return cp(x*b,y*b);}
	inline cp operator ~() const{return cp(x,-y);}
}x2[1<<20],y2[1<<20],z2[1<<20],w2[1<<20];
const double pi=acos(-1);
int rev[1<<20];
cp cc[1<<20][2];
int K,N;
double inv;
void fft(cp *a,int type){
	for(int i=0;i<N;i++){
		if(rev[i]>i) swap(a[i],a[rev[i]]);
	}
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j+=(1<<(i+1))){
			for(int l=j;l<j+(1<<i);l++){
				cp x=a[l]+cc[(l-j)<<(K-1-i)][type]*a[l+(1<<i)],y=a[l]-cc[(l-j)<<(K-1-i)][type]*a[l+(1<<i)];
				a[l]=x;
				a[l+(1<<i)]=y;
			}
		}
	}
	if(type) {
		for(int i=0;i<N;i++) a[i]=a[i]*inv;
	}
} 
void multiply(int n,int m){
	for(K=1;;K++){
		if((1<<K)>n+m+2) break;
	}
	N=(1<<K);
	inv=1.0/N;
	for(int i=0;i<N;i++){
		rev[i]=0;
		for(int j=0;j<K;j++){
			if((i>>j)&1) rev[i]^=(1<<(K-1-j));
		}
	}
	for(int i=0;i<N;i++) cc[i][0]=cp(cos((2*pi*i)/N),sin((2*pi*i)/N));
	for(int i=0;i<N;i++) cc[i][1]=cp(cos((2*pi*i)/N),-sin((2*pi*i)/N));
	for(int i=0;i<=n;i++) x2[i]=cp(f[i]/C,f[i]%C);
	for(int i=n+1;i<N;i++) x2[i]=cp(0,0);
	fft(x2,0);
	for(int i=0;i<=m;i++) y2[i]=cp(g[i]/C,g[i]%C);
	for(int i=m+1;i<N;i++) y2[i]=cp(0,0);
	fft(y2,0);
	for(int i=0;i<N;i++) z2[i]=x2[i]*y2[i];
	fft(z2,1);
	w2[0]=(~x2[0])*y2[0];
	for(int i=1;i<N;i++) w2[i]=(~x2[N-i])*y2[i];
	fft(w2,1);
	for(int i=0;i<=n+m;i++){
		long long xxx,yyy,zzz;
		yyy=z2[i].y+0.4;
		yyy%=p;
		xxx=(z2[i].x+w2[i].x)/2+0.4;
		xxx%=p;
		zzz=(w2[i].x-z2[i].x)/2+0.4;
		zzz%=p;
		h[i]=(xxx*C*C+yyy*C+zzz)%p;
	}
}
int k;
int ans[40000];
int fac[40000];
int infac[40000];
void cal(int n){
	if(n==1){
		ans[0]=0;
		for(int i=1;i<=k;i++) ans[i]=1;
		return;
	}
	int m=n/2;
    cal(m);
	for(int i=0;i<=k;i++) f[i]=(1ll*ans[i]*infac[i])%p;
	int u=qow(2,m);
	int uu=1;
	for(int i=0;i<=k;i++){
		g[i]=(((1ll*ans[i]*infac[i])%p)*uu)%p;
		uu=(1ll*uu*u)%p;
	}
	multiply(k,k);
	for(int i=0;i<=k;i++) ans[i]=(1ll*h[i]*fac[i])%p;
	if(n&1){
		uu=1;
		for(int i=0;i<=k;i++){
		    f[i]=(((1ll*ans[i]*infac[i])%p)*uu)%p;
		    uu=(uu*2ll)%p;
		}
		for(int i=1;i<=k;i++) g[i]=infac[i];
		g[0]=0;
		multiply(k,k);
		for(int i=0;i<=k;i++) ans[i]=(1ll*h[i]*fac[i])%p;
	}
}
int main(){
	int n;
	long long nn;
	scanf("%lld%d",&nn,&k);
	if(nn>k){
		printf("0");
		return 0;
	}
	n=nn;
	fac[0]=1;
	for(int i=1;i<=k;i++) fac[i]=(1ll*fac[i-1]*i)%p;
	for(int i=0;i<=k;i++) infac[i]=inverse(fac[i]);
	cal(n);
	int anss=0;
	for(int i=0;i<=k;i++) anss=(anss+((1ll*infac[k-i]*ans[i])%p)*infac[i])%p;
	printf("%lld",(1ll*fac[k]*anss)%p);
	return 0;
}