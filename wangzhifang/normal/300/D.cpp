#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 7340033
#define max_len 4096
#define max_k 1000
#define max_logn 30
using namespace std;
int dp[max_len];
long long w[2][21];
template<typename T>void init(T*a,int len,int half){
	dp[0]=0;
	for(int i=0; ++i<len; (dp[i]=dp[i>>1]>>1|((i&1)?half:0))>i&&(swap(a[i],a[dp[i]]),0));
}
long long quickpow(long long a,long long k){
	long long ret=1;
	for(; k; k>>=1,a=a*a%mod)
		(k&1)&&(ret=ret*a%mod);
	return ret;
}
long long m(long long x){
	return x>=mod?x-mod:x;
}
template<typename T>void fft(T*a,int len,bool iv=0){
	init(a,len,len>>1);
	for(int i=1,half=1,now=1; (i<<=1)<=len; half=i,++now)
		for(int j=0; j<len; j+=i)
			for(T*p=a+j,*q=p+half,*l=q,wk=1,tmp; p<l; ++p,++q,wk=wk*w[iv][now]%mod){
				tmp=(*q)*wk%mod;
				*q=m(*p-tmp+mod),
				*p=m(*p+tmp);
			}
}
template<typename T>void ifft(T*a,int len){
	fft(a,len,1);
	long long iv=quickpow(len,mod-2);
	for(int i=-1; ++i<len; a[i]=a[i]*iv%mod);
}
struct polynomial{
	long long a[max_len];
	int n;
};
polynomial pow4(polynomial x){
	int len=(x.n+1)<<2;
	while(len&(len-1))
		len+=len&(-len);
	fft(x.a,len);
	for(int i=-1; ++i<len; x.a[i]=x.a[i]*x.a[i]%mod)
		x.a[i]=x.a[i]*x.a[i]%mod;
	ifft(x.a,len); 
	(x.n<<=2)>max_k&&(x.n=max_k,memset(x.a+max_k,0,sizeof(x.a)-sizeof(long long)*(max_k+1)));
	return x;
}
polynomial ans[max_logn+1];
int now;
int main(){
	w[0][20]=2187,w[1][20]=4665133;
	for(int i=21; --i; w[0][i-1]=w[0][i]*w[0][i]%mod,w[1][i-1]=w[1][i]*w[1][i]%mod);
	int q,n,k,cnt;
	memset(ans[0].a,0,sizeof(ans[0].a));
	scanf("%d",&q),now=0,ans[0].n=0,ans[0].a[0]=1;
	for(++q; --q; ){
		for(scanf("%d%d",&n,&k),cnt=0; n&1; n>>=1,++cnt);
		for(!n&&(--cnt); ++now<=cnt; ans[now].a[0]=1){
			ans[now]=pow4(ans[now-1]);
			memcpy(ans[now].a+1,ans[now].a,(++ans[now].n)*sizeof(long long));
		}
		--now;
		printf("%lld\n",ans[cnt].a[k]);
	}
	return 0;
}