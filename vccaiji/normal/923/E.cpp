#include<bits/stdc++.h>
using namespace std;
const long long p=998244353,g=3;
int N,o;
inline long long qow(long long a,long long n){
	long long ans=1;
	for(a%=p;n;n>>=1){
		if(n&1) ans=(a*ans)%p;
		a=(a*a)%p;
	}
	return ans;
}
inline long long inverse(long long a){//a>=0
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
long long h[1<<21];
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
long long fac[110000];
long long infac[110000];
int main()
{
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%p;
	for(int i=0;i<=n;i++) infac[i]=inverse(fac[i]);
	for(int i=0;i<=n;i++){
		scanf("%lld",&f2[i]);
		f2[i]=(fac[i]*f2[i])%p;
	} 
	for(int i=0;i<=n;i++) g2[i]=infac[n-i];
	multiply(n,n);
	for(int i=0;i<=n;i++) f2[i]=(infac[i]*h2[i+n])%p;
	for(int i=0;i<=n;i++) f2[i]=(f2[i]*qow(inverse(i+1),m))%p;
	for(int i=0;i<=n;i++) f2[i]=(f2[i]*fac[i])%p;
	for(int i=0;i<=n;i++){
		if((n-i)&1) g2[i]=p-infac[n-i];
		else g2[i]=infac[n-i];
	}
	multiply(n,n);
	for(int i=0;i<=n;i++) printf("%lld ",(h2[n+i]*infac[i])%p);
	return 0;
}