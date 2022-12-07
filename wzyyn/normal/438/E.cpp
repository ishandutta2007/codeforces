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
const int FFTN=1<<18;
const int N=FFTN+5;
int W[N],w[N],R[N];
int A[N],B[N],C[N],D[N],E[N];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)	
		if (y&1) s=1ll*s*x%mo;
	return s;
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
		for (int i=0;i<n;i+=d<<1)
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
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
void getinv(int *C,int *D,int n){
	if (n==1){
		assert(C[0]);
		D[0]=power(C[0],mo-2);
		return;
	}
	int nn=(n+1)/2;
	getinv(C,D,nn);
	int L=FFTinit(2*n);
	For(i,0,L-1) A[i]=(i<n?C[i]:0);
	For(i,0,L-1) B[i]=(i<nn?D[i]:0);
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*B[i]*(2ll+mo-1ll*B[i]*A[i]%mo)%mo;
	IDFT(A,L);	
	For(i,0,n-1) D[i]=A[i];
}
void getsqrt(int *C,int *D,int n){
	if (n==1){
		assert(C[0]==1);
		D[0]=1;
		return;
	}
	int nn=(n+1)/2;
	getsqrt(C,D,(n+1)/2);
	getinv(D,E,n);
	int L=FFTinit(2*n);
	For(i,0,L-1) A[i]=(i<n?C[i]:0);
	For(i,0,L-1) B[i]=(i<n?E[i]:0);
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	For(i,0,n-1) D[i]=1ll*(D[i]+A[i])*(mo+1)/2%mo;
}
/*
(A^2-X)=0
(A^2+X)^2=4A^2X
*/
int main(){
	int n,m,x;
	FFTinit();
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&x),C[x]=mo-4;
	C[0]=1;
	getsqrt(C,D,m+1);
	++D[0];
	getinv(D,C,m+1);
	For(i,1,m) printf("%d\n",2*C[i]%mo);
}
/*
3 3
1 1 2 1
*/