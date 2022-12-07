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
const int FFTN=(1<<20);
const int N=FFTN+5;
const int M=805;
char s[M][M],t[M][M];
int n,m,nn,mm,nnn,mmm;
int W[N],w[N],R[N];
int A[N],B[N],C[N];
int a[N],b[N];
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
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y; 
			}
		if (d==1<<10)
			For(i,0,n-1) p[i]%=mo;
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
		if (d==1<<10)
			For(i,0,n-1) p[i]%=mo;
	}
	int v=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*v%mo;
}
int main(){
	FFTinit();
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	scanf("%d%d",&nn,&mm);
	For(i,1,nn) scanf("%s",t[i]+1);
	//cout<<233<<endl; 
	nnn=nn+n-1; mmm=mm+m-1;
	For(i,1,nnn) For(j,1,mmm)
		s[i][j]=s[(i-1)%n+1][(j-1)%m+1];
	For(i,1,nnn) For(j,1,mmm)
		a[i*mmm-mmm+j]=(s[i][j]-'a'+1);
	For(i,1,nn) For(j,1,mm)
		b[i*mmm-mmm+j-1]=(t[i][j]=='?'?0:t[i][j]-'a'+1);
	reverse(b,b+nn*mmm+1);
	//cout<<233<<endl; 
	int L=FFTinit((nn+nnn)*mmm);
	//cout<<233<<endl; 
	For(i,0,L-1) A[i]=B[i]=0;
	For(i,0,L-1) A[i]=a[i]*a[i],B[i]=b[i];
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) C[i]=(C[i]+1ll*A[i]*B[i])%mo;
	For(i,0,L-1) A[i]=B[i]=0;
	For(i,0,L-1) A[i]=a[i],B[i]=b[i]*b[i];
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) C[i]=(C[i]+mo-2ll*A[i]*B[i]%mo)%mo;
	For(i,0,L-1) A[i]=B[i]=0;
	For(i,0,L-1) A[i]=1,B[i]=b[i]*b[i]*b[i];
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) C[i]=(C[i]+1ll*A[i]*B[i])%mo;
	IDFT(C,L);
	For(i,1,n){
		For(j,1,m)
			putchar('0'+(C[nn*mmm+i*mmm-mmm+j]==0));
		puts("");
	}
}
/*
10 10
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaab
2 2
a?
?a
(a_i-b_i)^2*bi
ai^2bi+bi^3-2aibi^2
*/