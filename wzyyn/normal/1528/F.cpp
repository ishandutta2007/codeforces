#include<bits/stdc++.h>
using namespace std;

const int mo=998244353;
const int N=(1<<18)+5;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,k,f[N],inv[N];
int R[N],A[N],B[N];
void init(){
	inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
}
int FFTinit(int n){
	int nn=1;
	for (;nn<=n;nn<<=1);
	for (int i=0;i<nn;i++)
		R[i]=(R[i>>1]>>1)|((i&1)?(nn>>1):0);
	return nn;
}
void DFT(int *a,int n,int f){
	for (int i=0;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2)%mo;
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0,w=1;j<d;j++,w=1ll*wn*w%mo){
				int y=1ll*a[i+j+d]*w%mo;
				a[i+j+d]=(a[i+j]+mo-y)%mo;
				a[i+j]=(a[i+j]+y)%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	f[0]=1;
	for (int i=1;i<=min(k,n);i++)
		f[i]=1ll*f[i-1]*(n-i+1)%mo;
	for (int i=1;i<=min(k,n);i++)
		f[i]=1ll*f[i]*power(n+1,n-i)%mo;
	
	int L=FFTinit(2*k);
	for (int i=0;i<=k;i++)
		A[i]=1ll*inv[i]*power(i,k)%mo;
	for (int i=0;i<=k;i++)
		B[i]=1ll*inv[i]*(i&1?mo-1:1)%mo;
	DFT(A,L,1); DFT(B,L,1);
	for (int i=0;i<L;i++)
		A[i]=1ll*A[i]*B[i]%mo;
	DFT(A,L,-1);
	int ans=0;
	for (int i=1;i<=min(k,n);i++){
		//cout<<A[i]<<' '<<f[i]<<endl;
		ans=(ans+1ll*A[i]*f[i])%mo;
	}
	cout<<ans<<endl;
}
/*
f[i]=C(n,i)*(n+1)^(n-k-1)
*/