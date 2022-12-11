#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
void modp(int&x){
	x>=mod&&(x-=mod);
}
void modn(int&x){
	x<0&&(x+=mod);
}
void modma(int&x,const int a,const int b){
	x=(x+ll(a)*b)%mod;
}
constexpr int max_n=1000000;
int a[max_n+1],bbuf[max_n*2+1],cbuf[max_n*2+1];
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		char ch=getchar();
		if(ch=='(')
			a[i]=1;
		else
			if(ch==')')
				a[i]=-1;
			else
				--i;
	}
	memset(bbuf,0,(n*2+1)<<2);
	memset(cbuf,0,(n*2+1)<<2);
	int*b=bbuf+n,*c=cbuf+n;
	b[0]=1,c[0]=1;
	ll now=0,sumb=0,ans=0;
	for(int i=n; i; --i){
		if(a[i]==1){
			sumb+=b[0];
			now+=sumb;
			--b,--c;
			now-=c[0];
		}
		else{
			now+=c[0];
			++b,++c;
			now-=sumb;
			sumb-=b[0];
		}
//		fprintf(stderr,"%d: %lld %lld\n",i,now,sumb);
		ans+=now;
		++b[0],c[0]=n-i+2;
	}
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}