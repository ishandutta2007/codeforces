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
int a[max_n+1],b[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%1d",a+i);
	bool flg=0;
	for(int i=1; i<=n; ++i)
		scanf("%1d",b+i);
	flg=a[1]^b[1];
	for(int i=2; i<=n; ++i)
		if(flg!=(a[i]^b[i])){
			puts("NO");
			return;
		}
	puts("YES");
	vector<pair<int,int> >opt;
	for(int i=1; i<=n; ++i)
		if(a[i])
			opt.emplace_back(i,i),flg^=1;
	if(flg){
		opt.emplace_back(1,1);
		opt.emplace_back(2,n);
		opt.emplace_back(1,n);
	}
	printf("%zd\n",opt.size());
	for(const pair<int,int>&p:opt)
		printf("%d %d\n",p.first,p.second);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}