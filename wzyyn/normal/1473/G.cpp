#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int mo=998244353;
const int M=300005;
const int FFTN=1<<14;
const int N=FFTN+5;
int fac[M],inv[M];
int n,f[N],g[N];
int A[N],B[N],w[N],W[N],R[N];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,M-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,M-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,M-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int Binom(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void FFTinit(){
	w[0]=1;
	w[1]=power(3,(mo-1)/FFTN);
	For(i,2,N-1) w[i]=1ll*w[i-1]*w[1]%mo;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) W[i]=w[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*W[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	For(i,0,n-1) a[i]=p[i]%mo;
}

void IDFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) W[i]=w[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*W[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int v=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*v%mo;
}
int main(){
	init();
	FFTinit();
	scanf("%d",&n);
	f[0]=1;
	int l=0;
	For(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);
		int nl=l+a-b;
		int L=FFTinit(l+l+nl+5);
		For(i,0,L-1) A[i]=B[i]=0;
		For(i,0,l) A[i]=f[i];
		For(i,-l,nl) B[l+i]=Binom(a+b,b+i);
		DFT(A,L); DFT(B,L);
		For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
		IDFT(A,L);
		For(i,0,nl) f[i]=A[l+i];
		l=nl; 
	}
	int ans=0;
	For(i,0,l) ans=(ans+f[i])%mo;
	cout<<ans<<endl;
}