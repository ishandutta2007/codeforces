#include<bits/stdc++.h>
using namespace std;
const int p=490019;
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
int f[610000]={};
int g[1210000]={};
int h[2010000];
const int C=(1<<10);
struct cp{
	double x,y;
	inline cp() {}
	inline cp(double xx,double yy) :x(xx),y(yy) {}
	inline cp operator +(const cp &b) const{return cp(x+b.x,y+b.y);}
	inline cp operator -(const cp &b) const{return cp(x-b.x,y-b.y);}
	inline cp operator *(const cp &b) const{return cp(x*b.x-y*b.y,x*b.y+y*b.x);}
	inline cp operator *(const double &b) const{return cp(x*b,y*b);}
	inline cp operator ~() const{return cp(x,-y);}
}x2[1<<21],y2[1<<21],z2[1<<21],w2[1<<21];
const double pi=acos(-1);
int rev[1<<21];
cp cc[1<<21][2];
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
int gg[610000]={};
int main(){
	int n,m,c;
	scanf("%d%d%d",&n,&m,&c);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		f[(1ll*i*i)%(p-1)]=(f[(1ll*i*i)%(p-1)]+a)%p;
	}
	for(int i=0;i<m;i++){
		int b;
		scanf("%d",&b);
		gg[(((1ll*i*i)%(p-1))*i)%(p-1)]=(gg[(((1ll*i*i)%(p-1))*i)%(p-1)]+b)%p;
	}
	int aa=1,bb=1,ic=inverse(c);
	for(int i=0;i<p-1;i++){
		f[i]=(1ll*f[i]*aa)%p;
		aa=(1ll*aa*bb)%p;
		bb=(1ll*bb*ic)%p;
	}
	for(int i=0;i<p-1;i++){
		if(i<p-2-i) swap(f[i],f[p-2-i]);
	}
	aa=1,bb=1;
	for(int i=0;i<=2*(p-2);i++){
		g[i]=aa;
		aa=(1ll*aa*bb)%p;
		bb=(1ll*bb*c)%p;
	}
	multiply(p-2,2*(p-2));
	int ans=0;
	aa=1,bb=1;
	for(int i=0;i<p-1;i++){
		ans=(ans+((1ll*aa*gg[i])%p)*h[p-2+i])%p;
		aa=(1ll*aa*bb)%p;
		bb=(1ll*bb*ic)%p;
	}
	printf("%d",ans);
	return 0;
}