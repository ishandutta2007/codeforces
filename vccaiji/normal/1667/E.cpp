#include<bits/stdc++.h>
using namespace std;
const long long p=998244353,g=3;
int N,o;
long long qow(long long a,long long n){//a>=0
	if(n==0) return 1;
	long long t=qow(a,n>>1);
	t=(t*t)%p;
	if(n&1) return (a*t)%p;
	return t;
}
long long inverse(long long a){//a>=0
	return qow(a,p-2);
}
long long f[1<<21];
int rev[1<<21];
void getrev(){
	for(int i=0;i<N;i++){
		rev[i]=0;
		for(int j=0;j<o;j++){
			if((i>>j)&1) rev[i]^=(1<<(o-1-j));
		}
	}
}
void fft(){
	for(int i=0;i<N;i++){
		if(rev[i]>i){
			long long u=f[i];
			f[i]=f[rev[i]];
			f[rev[i]]=u;
		}
	}
	for(int i=1;i<=o;i++){
		int M=(1<<(i-1));
		long long w=qow(g,(p-1)>>i);
		for(int l=0;l<N;l+=(1<<i)){
			long long w1=1;
			for(int ll=l;ll<l+M;ll++){
			    long long x=(f[ll]+f[ll+M]*w1)%p,y=(f[ll]-f[ll+M]*w1)%p;
			    if(y<0) y+=p;
				f[ll]=x,f[ll+M]=y;	
				w1=(w1*w)%p;
			}
		}
	}
}
long long gg[1<<21];
long long hh[1<<21];
long long h[1<<21];
void inver(int n){
	if(n==1){
		gg[0]=inverse(hh[0]);
		return;
	}
	inver((n+1)/2);
	for(o=1;;o++){
		if((1<<o)>2*n) break;
	}
	N=(1<<o);
	getrev();
	for(int i=0;i<(n+1)/2;i++) f[i]=gg[i];
	for(int i=(n+1)/2;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) h[i]=f[i];
	for(int i=0;i<n;i++) f[i]=hh[i];
	for(int i=n;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) f[i]=(((f[i]*h[i])%p)*h[i])%p;
	fft();
	for(int i=1;i<N;i++) h[i]=f[N-i];
	h[0]=f[0];
	int inv=inverse(N);
	for(int i=0;i<N;i++) h[i]=(h[i]*inv)%p;
	for(int i=(n+1)/2;i<n;i++) gg[i]=(p-h[i])%p;
}
long long wws[1<<21];
long long wwss[1<<21];
void ln(int n){
	for(int i=0;i<n;i++) hh[i]=wwss[i];
	inver(n-1);
	for(o=1;;o++){
		if((1<<o)>2*n) break;
	}
	N=(1<<o);
	getrev(); 
	for(int i=0;i<n-1;i++) f[i]=gg[i];
	for(int i=n-1;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) h[i]=f[i];
	for(int i=0;i<n-1;i++) f[i]=((i+1)*wwss[i+1])%p; 
	for(int i=n-1;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) f[i]=(f[i]*h[i])%p;
	fft();
	h[0]=f[0];
	for(int i=1;i<N;i++) h[i]=f[N-i];
	long long inv=inverse(N);
	for(int i=0;i<N;i++) h[i]=(inv*h[i])%p;
	wws[0]=0;
	for(int i=0;i<n-1;i++) wws[i+1]=(h[i]*inverse(i+1))%p;
}
long long ww[1<<21];
long long w[1<<21];
void exp(int n){
	if(n==1){
		w[0]=1;
		return;
	} 
	exp((n+1)/2);
	for(int i=0;i<(n+1)/2;i++) wwss[i]=w[i];
	for(int i=(n+1)/2;i<n;i++) wwss[i]=0;
	ln(n);
	for(int i=0;i<n;i++) f[i]=(ww[i]-wws[i]+p)%p;
	for(o=1;;o++){
		if((1<<o)>2*n) break;
	}
	N=(1<<o);
	getrev();
	for(int i=n;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) h[i]=f[i];
	for(int i=0;i<(n+1)/2;i++) f[i]=w[i];
	for(int i=(n+1)/2;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) f[i]=(f[i]*h[i])%p;
	fft();
	h[0]=f[0];
	for(int i=1;i<N;i++) h[N-i]=f[i];
	long long inv=inverse(N);
	for(int i=(n+1)/2;i<n;i++) w[i]=(h[i]*inv)%p;
}
long long f2[1<<21];
long long g2[1<<21];
long long h2[1<<21];
void multiply(int n,int m){
	for(o=1;;o++){
		if((1<<o)>n+m+2) break;
	}
	N=(1<<o);
	getrev();
	for(int i=0;i<=n;i++) f[i]=f2[i];
	for(int i=n+1;i<N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) h[i]=f[i];
	for(int i=0;i<=m;i++) f[i]=g2[i];
	for(int i=m+1;i<=N;i++) f[i]=0;
	fft();
	for(int i=0;i<N;i++) f[i]=(f[i]*h[i])%p;
	fft();
	long long inv=inverse(N);
	h[0]=(inv*f[0])%p;
	for(int i=1;i<N;i++) h[i]=(inv*f[N-i])%p;
	for(int i=0;i<=n+m;i++) h2[i]=h[i];
}
int ans[210000];
int inv[210000];
int fac[210000];
int infac[210000];
int t[210000];
int main(){
	int n,m;
	cin>>n;
	m=(n-1)/2;
	for(int i=1;i<=n;i++)inv[i]=inverse(i);
	fac[0]=infac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%p;
	for(int i=1;i<=n;i++)infac[i]=1ll*infac[i-1]*inv[i]%p;
	for(int i=1;i<=m;i++) ww[i]=inv[i];
	exp(n);
	for(int i=0;i<n;i++)t[i]=1ll*fac[i]*w[i]%p;
	ans[1]=t[n-1];
	for(int i=0;i<=n;i++)g2[i]=infac[i];
	for(int i=m;i<=n-2;i++)f2[i]=(1ll*t[i]*infac[i]%p*fac[n-2-i])%p;
	multiply(n,n);
	for(int i=2;i<=n;i++)ans[i]=1ll*fac[n-i]*(i-1)%p*h2[n-i]%p;
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}