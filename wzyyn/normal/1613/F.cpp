#include<bits/stdc++.h>

using namespace std;

const int mo=998244353;
const int FFTN=1<<18;
const int N=FFTN+5;
int n,m,deg[N],fac[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int w[N],W[N],R[N];
int A[N],B[N];
unsigned long long p[N];
void init(){
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	for (int i=2;i<N;i++)
		W[i]=1ll*W[i-1]*W[1]%mo;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	for (int i=0;i<L;i++)
		R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(int *a,int n){
	for (int i=0;i<n;i++)
		p[R[i]]=a[i];
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
	for (int i=0;i<n;i++)
		a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	for (int i=0;i<n;i++)
		p[R[i]]=a[i];
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
	int inv=power(n,mo-2);
	for (int i=0;i<n;i++)
		a[i]=p[i]*inv%mo;
}
vector<int> Mul(vector<int> a,vector<int> b){
	int sza=a.size(),szb=b.size();
	int L=FFTinit(sza+szb-1);
	for (int i=0;i<L;i++) A[i]=(i<sza?a[i]:0);
	for (int i=0;i<L;i++) B[i]=(i<szb?b[i]:0);
	DFT(A,L); DFT(B,L);
	for (int i=0;i<L;i++) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	vector<int> ans(A,A+sza+szb-1);
	return ans;
}
vector<int> divide(int l,int r){
	if (l==r){
		vector<int> v;
		v.push_back(1);
		if (deg[l]) v.push_back(deg[l]);
		return v;
	}
	int mid=(l+r)/2;
	return Mul(divide(l,mid),divide(mid+1,r));
}
int main(){
	init();
	FFTinit();
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		++deg[x]; ++deg[y];
	}
	for (int i=2;i<=n;i++)
		--deg[i];
	vector<int> v=divide(1,n);
	int ans=0;
	for (int i=0;i<v.size();i++)
		ans=(ans+1ll*(i&1?mo-1:1)*fac[n-i]%mo*v[i])%mo;
	cout<<ans<<endl;
}