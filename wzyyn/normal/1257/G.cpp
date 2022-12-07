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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int mo=998244353;
const int FFTN=262144;
const int N=FFTN+5;
int *f[N],len[N];
int A[N],B[N],W[N],w[N];
int n,a[N],b[N],R[N];
int MEM[N*4],*MEMP=MEM;
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
				int tmp=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-tmp;
				p[i+j]+=tmp;
			}
	}
	For(i,0,n-1)
		a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int tmp=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-tmp;
				p[i+j]+=tmp;
			}
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
void solve(int l,int r){
	if (l==r){
		f[l]=MEMP;
		len[l]=b[l];
		MEMP=MEMP+b[l]+2;
		For(i,0,b[l]) f[l][i]=1;
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int L=FFTinit(len[l]+len[mid+1]);
	For(i,0,L-1) A[i]=B[i]=0;
	For(i,0,len[l]) A[i]=f[l][i];
	For(i,0,len[mid+1]) B[i]=f[mid+1][i];
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	//For(i,0,L-1) printf("%d ",A[i]); puts("");
	len[l]+=len[mid+1];
	For(i,0,len[l]) f[l][i]=A[i];
}
int main(){
	FFTinit();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1;
	For(i,2,n+1)
		if (a[i]!=a[i-1])
			b[++*b]=i-l,l=i;
	solve(1,*b);
	printf("%d\n",f[1][(len[1]+1)/2]);
}