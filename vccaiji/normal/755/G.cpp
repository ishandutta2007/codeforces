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
const long long gi=inverse(g);
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
void fft(int type){
	for(int i=0;i<N;i++){
		if(rev[i]>i){
			long long u=f[i];
			f[i]=f[rev[i]];
			f[rev[i]]=u;
		}
	}
	for(int i=1;i<=o;i++){
		int M=(1<<(i-1));
		long long w=qow(type==1 ? g : gi,(p-1)>>i);
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
	if(type!=1){
		long long inv=inverse(N);
		for(int i=0;i<N;i++) f[i]=(f[i]*inv)%p;
	}
}
long long aa[1<<17]={1,1};
long long bb[1<<17]={0,1};
long long cc[1<<17]={1};
long long dd[1<<17]={};
long long aa2[1<<17]={1};
long long bb2[1<<17]={};
long long cc2[1<<17]={};
long long dd2[1<<17]={1};
long long aa3[1<<17];
long long bb3[1<<17];
long long cc3[1<<17];
long long dd3[1<<17];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(o=1;;o++){
		if((1<<o)>2*k) break;
	}
	N=(1<<o);
	getrev();
	for(;n;n>>=1){
		for(int i=0;i<=k;i++) f[i]=aa[i];
		for(int i=k+1;i<N;i++) f[i]=0;
		fft(1);
		for(int i=0;i<N;i++) aa[i]=f[i];
		for(int i=0;i<=k;i++) f[i]=bb[i];
		for(int i=k+1;i<N;i++) f[i]=0;
		fft(1);
		for(int i=0;i<N;i++) bb[i]=f[i];
		for(int i=0;i<=k;i++) f[i]=cc[i];
		for(int i=k+1;i<N;i++) f[i]=0;
		fft(1);
		for(int i=0;i<N;i++) cc[i]=f[i];
		for(int i=0;i<=k;i++) f[i]=dd[i];
		for(int i=k+1;i<N;i++) f[i]=0;
		fft(1);
		for(int i=0;i<N;i++) dd[i]=f[i];
		if(n&1){
			for(int i=0;i<=k;i++) f[i]=aa2[i];
			for(int i=k+1;i<N;i++) f[i]=0;
			fft(1);
			for(int i=0;i<N;i++) aa2[i]=f[i];
			for(int i=0;i<=k;i++) f[i]=bb2[i];
			for(int i=k+1;i<N;i++) f[i]=0;
			fft(1);
			for(int i=0;i<N;i++) bb2[i]=f[i];
			for(int i=0;i<=k;i++) f[i]=cc2[i];
			for(int i=k+1;i<N;i++) f[i]=0;
			fft(1);
			for(int i=0;i<N;i++) cc2[i]=f[i];
			for(int i=0;i<=k;i++) f[i]=dd2[i];
			for(int i=k+1;i<N;i++) f[i]=0;
			fft(1);
			for(int i=0;i<N;i++) dd2[i]=f[i];
			for(int i=0;i<N;i++) aa3[i]=(aa[i]*aa2[i]+bb[i]*cc2[i])%p;
			for(int i=0;i<N;i++) bb3[i]=(aa[i]*bb2[i]+bb[i]*dd2[i])%p;
			for(int i=0;i<N;i++) cc3[i]=(cc[i]*aa2[i]+dd[i]*cc2[i])%p;
			for(int i=0;i<N;i++) dd3[i]=(cc[i]*bb2[i]+dd[i]*dd2[i])%p;
			for(int i=0;i<N;i++) f[i]=aa3[i];
			fft(-1);
			for(int i=0;i<=k;i++) aa2[i]=f[i];
			for(int i=0;i<N;i++) f[i]=bb3[i];
			fft(-1);
			for(int i=0;i<=k;i++) bb2[i]=f[i];
			for(int i=0;i<N;i++) f[i]=cc3[i];
			fft(-1);
			for(int i=0;i<=k;i++) cc2[i]=f[i];
			for(int i=0;i<N;i++) f[i]=dd3[i];
			fft(-1);
			for(int i=0;i<=k;i++) dd2[i]=f[i];
		}
		for(int i=0;i<N;i++) aa3[i]=(aa[i]*aa[i]+bb[i]*cc[i])%p;
		for(int i=0;i<N;i++) bb3[i]=(aa[i]*bb[i]+bb[i]*dd[i])%p;
		for(int i=0;i<N;i++) cc3[i]=(cc[i]*aa[i]+dd[i]*cc[i])%p;
		for(int i=0;i<N;i++) dd3[i]=(cc[i]*bb[i]+dd[i]*dd[i])%p;
		for(int i=0;i<N;i++) f[i]=aa3[i];
		fft(-1);
		for(int i=0;i<=k;i++) aa[i]=f[i];
		for(int i=0;i<N;i++) f[i]=bb3[i];
		fft(-1);
		for(int i=0;i<=k;i++) bb[i]=f[i];
		for(int i=0;i<N;i++) f[i]=cc3[i];
		fft(-1);
		for(int i=0;i<=k;i++) cc[i]=f[i];
		for(int i=0;i<N;i++) f[i]=dd3[i];
		fft(-1);
		for(int i=0;i<=k;i++) dd[i]=f[i];
	}
	for(int i=1;i<=k;i++) printf("%lld ",aa2[i]);
	return 0;
}