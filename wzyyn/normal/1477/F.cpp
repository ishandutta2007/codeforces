#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
const int mo=998244353;
const int FFTN=1<<18;
const int N=FFTN+5;
int n,K,S,L[55];
vector<int> v[55];
int fac[N],inv[N];
int w[N],W[N],R[N];
int A[N],B[N];
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
vector<int> divide(int l,int r){
	if (l==r) return v[l];
	int mid=(l+r)/2;
	vector<int> vl=divide(l,mid);
	vector<int> vr=divide(mid+1,r);
	int sza=vl.size(),szb=vr.size();
	int L=FFTinit(sza+szb);
	For(i,0,L-1) A[i]=B[i]=0;
	For(i,0,sza-1) A[i]=vl[i];
	For(i,0,szb-1) B[i]=vr[i];
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	vector<int> re;
	re.resize(sza+szb-1);
	For(i,0,sza+szb-2) re[i]=A[i];
	return re;
}
int main(){
	init();
	FFTinit();
	scanf("%d%d",&n,&K);
	For(i,1,n) scanf("%d",&L[i]),S+=L[i];
	int M=S+2;
	For(i,1,n){
		v[i].resize(2*M);
		v[i][0]=1;
		For(j,1,(L[i]-1)/K){
			int C0=1ll*power(L[i]-j*K,j  )*power(S,mo-1-j    )%mo*inv[j  ]%mo; 
			int C1=1ll*power(L[i]-j*K,j-1)*power(S,mo-1-(j-1))%mo*inv[j-1]%mo; 
			if (j&1) C0=mo-C0,C1=mo-C1;
			v[i][j]=C0; v[i][j+M]=C1;
		}
	}
	vector<int> temp=divide(1,n);
	For(i,0,temp.size()-1)
		temp[i]=(mo-temp[i])%mo;
	temp[0]=(temp[0]+1)%mo; 
	int ans=0;
	For(i,0,n) For(j,0,S) if (temp[i*M+j]){
		int c0=1ll*(S-j*K)*power(S,mo-2)%mo,c1=j-i;
		int re=1ll*power(1+mo-c0,mo-1-(c1+1))%mo;
		ans=(ans+1ll*fac[c1]*re%mo*temp[i*M+j])%mo;
	}
	cout<<ans<<endl;
}
//(x/(1-0.5x)^2)
//1 0.5 0.25 0.125 .....
//
/*
2x/(1-0.5x)^2
*/