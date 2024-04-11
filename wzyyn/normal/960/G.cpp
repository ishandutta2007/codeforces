#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=998244353;
const int FFTN=(1<<17);
const int N=FFTN+5;
int n,va,vb;
int fac[N],inv[N];
int W[N],w[N],R[N];
int A[N],B[N],a[N];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	For(i,2,N-1) W[i]=1ll*W[i-1]*W[1]%mo;
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
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
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
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
void solve(int n){
	if (n==1){
		a[1]=1;
		return;
	}
	solve(n/2);
	int L=FFTinit(n);
	For(i,0,N-1) A[i]=B[i]=0; B[0]=1;
	For(i,0,n/2) A[i]=1ll*a[i]*fac[i]%mo;
	For(i,1,n/2) B[i]=1ll*B[i-1]*(n/2)%mo;
	For(i,0,n/2) B[i]=1ll*B[i]*inv[i]%mo;
	reverse(B,B+n/2+1);
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	For(i,0,n/2) A[i]=1ll*A[i+n/2]*inv[i]%mo;
	For(i,n/2+1,L-1) A[i]=0;
	For(i,0,L-1) B[i]=0;
	For(i,0,n/2) B[i]=a[i];
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L); 
	For(i,0,n) a[i]=A[i];
	if (n&1)
		Rep(i,n,1)
			a[i]=(1ll*a[i]*(n-1)+a[i-1])%mo;
	//printf("%d\n",n);
	//For(i,0,n) printf("%d ",a[i]); puts("");
}
int STL(int n,int k){
	solve(n);
	return a[k];
}
int main(){
	init(); FFTinit();
	scanf("%d%d%d",&n,&va,&vb);
	if (va+vb-2>n-1||!va||!vb) return puts("0"),0;
	if (n==1) return puts("1"),0;
	printf("%lld\n",1ll*STL(n-1,va+vb-2)*C(va+vb-2,vb-1)%mo);
}
/*

*/