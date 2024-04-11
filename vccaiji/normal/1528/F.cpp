#include<bits/stdc++.h>
using namespace std;
const long long p=998244353,g=3;
int N,o;
long long qow(long long a,long long n){
	long long t=1;
	for(a%=p;n;n>>=1){
		if(n&1) t=(t*a)%p;
		a=(a*a)%p; 
	}
	return t;
}
long long inverse(long long a){//a>=0
	return qow(a,p-2);
}
long long f[1<<21];
int rev[1<<21];
long long rt[1<<21];
void getrev(){
    long long rtt=qow(g,(p-1)>>o);
    rev[0]=0;
    rt[0]=1;
    for(int i=0;i<o;i++) rev[1<<i]=(1<<(o-1-i));
	for(int i=1;i<N;i++){
		rev[i]=rev[i^(i&(-i))]^rev[i&(-i)];
        rt[i]=(rt[i-1]*rtt)%p;
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
		//long long w=qow(g,(p-1)>>i);
		for(int l=0;l<N;l+=(1<<i)){
			//long long w1=1;
			for(int ll=l;ll<l+M;ll++){
                long long w1=rt[(ll-l)<<(o-i)];
			    long long x=(f[ll]+f[ll+M]*w1)%p,y=(f[ll]-f[ll+M]*w1)%p;
			    if(y<0) y+=p;
				f[ll]=x,f[ll+M]=y;	
				//w1=(w1*w)%p;
			}
		}
	}
}
long long h[1<<21];
long long f2[1<<21];
long long g2[1<<21];
long long h2[1<<21];
void multiply(int n,int m){
	for(o=1;;o++) if((1<<o)>n+m) break;
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
int a[21000];
int fac[110000];
int infac[110000];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=k;i++) fac[i]=((long long)fac[i-1]*i)%p;
	for(int i=0;i<=k;i++) infac[i]=inverse(fac[i]);
	for(int i=0;i<=k;i++) f2[i]=(qow(i,k)*infac[i])%p;
	for(int i=0;i<=k;i++){
		if(i&1) g2[i]=p-infac[i];
		else g2[i]=infac[i];
	}
	multiply(k,k);
	int ans=0;
	for(int i=0,j=1;i<=min(k,n);i++,j=((long long)j*(n-i+1))%p) ans=(ans+1ll*h2[i]*j%p*qow(n+1,n-i))%p;
	cout<<ans;
	return 0;
}