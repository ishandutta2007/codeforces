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
const int FFTN=1<<16;
const int N=FFTN+5;
int w[N],W[N],R[N];
int A[N],B[N],C[N];
int D[N],E[N],F[N];
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

int n,g[N];
int g0[N],g1[N],g2[N];
int f0[N],f1[N],f2[N];

void divide(int l,int r){
	if (l==r){
		f0[l]=(f0[l]+g0[l])%mo;
		f1[l]=(f1[l]+g1[l])%mo;
		f2[l]=(f2[l]+g2[l])%mo;
		//cout<<f0[l]<<' '<<f1[l]<<' '<<f2[l]<<endl;
		return;
	}
	int mid=(l+r)/2;
	divide(l,mid);
	int L=FFTinit(r-l+10);
	For(i,0,L-1) A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=0;
	For(i,l,mid) A[i-l]=f0[i],B[i-l]=f1[i],C[i-l]=f2[i];
	For(i,0,r-l) D[i]=g0[i],E[i]=g1[i],F[i]=g2[i];
	DFT(A,L); DFT(B,L); DFT(C,L);
	DFT(D,L); DFT(E,L); DFT(F,L);
	For(i,0,L-1){
		C[i]=1ll*C[i]*F[i]%mo;
		F[i]=1ll*F[i]*B[i]%mo;
		B[i]=1ll*B[i]*E[i]%mo;
		E[i]=1ll*E[i]*A[i]%mo;
		A[i]=1ll*A[i]*D[i]%mo;
	} 
	IDFT(A,L); IDFT(B,L); IDFT(C,L);
	IDFT(D,L); IDFT(E,L); IDFT(F,L);
	For(i,mid+1,r){
		f0[i]=(1ll*f0[i]+A[i-l-1]+(i>=l+3?B[i-l-3]:0))%mo;
		f1[i]=(1ll*f1[i]+E[i-l-1]+(i>=l+3?F[i-l-3]:0))%mo;
		f2[i]=(1ll*f2[i]+B[i-l-1]+(i>=l+3?C[i-l-3]:0))%mo;
	}
	divide(mid+1,r);
}
int main(){
	FFTinit();
	scanf("%d",&n);
	g[0]=1; g[2]=1;
	for (int i=4;i<=n;i+=2)
		g[i]=(g[i-2]+g[i-4])%mo;
	For(i,0,n){
		g0[i]=1ll*g[i]*i*i%mo;
		g1[i]=1ll*g[i]*(i+1)*(i+1)%mo;
		g2[i]=1ll*g[i]*(i+2)*(i+2)%mo;
	}
	//cout<<g[6]<<endl;
	/*for (int i=0;i<=n;i++){
		f0[i]=g0[i]; f1[i]=g1[i]; f2[i]=g2[i];
		for (int j=0;j<=i-1;j++){
			f0[i]=(f0[i]+1ll*f0[j]*g0[i-j-1])%mo;
			f1[i]=(f1[i]+1ll*f0[j]*g1[i-j-1])%mo;
			f2[i]=(f2[i]+1ll*f1[j]*g1[i-j-1])%mo;
		}
		for (int j=0;j<=i-3;j++){
			f0[i]=(f0[i]+1ll*f1[j]*g1[i-j-3])%mo;
			f1[i]=(f1[i]+1ll*f1[j]*g2[i-j-3])%mo;
			f2[i]=(f2[i]+1ll*f2[j]*g2[i-j-3])%mo;
		}
	}*/
	divide(0,n);
	int ans=0;
	ans=(ans+1ll*n*g0[n-1])%mo;
	//cerr<<ans<<endl;
	ans=(ans+1ll*n*g2[n-3])%mo;
	//cerr<<ans<<endl;
	For(i,0,n-2) ans=(ans+1ll*g0[i]*f0[n-i-2]%mo*(i+1))%mo;
	For(i,0,n-4) ans=(ans+2ll*g1[i]*f1[n-i-4]%mo*(i+2))%mo;
	For(i,0,n-6) ans=(ans+1ll*g2[i]*f2[n-i-6]%mo*(i+3))%mo;
	printf("%d\n",ans);
}