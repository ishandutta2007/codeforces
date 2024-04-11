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
}// 
int d[300000]={};
long long aa[300000];
void solve(int l,int r){
	if(l==r){
		aa[l]=d[l];
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	f2[0]=1;
	for(int i=1;i<=mid-l+1;i++) f2[i]=aa[l+i-1];
	g2[0]=1;
	for(int i=1;i<=r-mid;i++) g2[i]=aa[mid+i];
	multiply(mid-l+1,r-mid);
	for(int i=l;i<=r;i++) aa[i]=h2[i-l+1];
}
long long fac[300000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++;
		d[y]++;
	}
	for(int i=2;i<=n;i++) d[i]--;
	for(int i=1;i<=n;i++) d[i]=(p-d[i])%p;
	solve(1,n);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%p;
	long long ans=fac[n];
	for(int i=1;i<=n;i++) ans=(ans+aa[i]*fac[n-i])%p;
	printf("%lld",ans);
	return 0;
}