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
int cnt[26];
void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; ++i){
		char ch;
		while(!islower(ch=getchar()));
		++cnt[ch-'a'];
	}
	const int m=n/k;
	for(int i=1,j; i<=k; ++i){
		for(j=0; j<m&&cnt[j]; ++j)
			--cnt[j];
		putchar('a'+j);
	}
	putchar('\n');
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}