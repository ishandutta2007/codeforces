#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
void test(){
	int n;
	scanf("%d",&n);
	if(n<100){
		putchar((n%10)|'0');
		putchar('\n');
	}
	else{
		int ans=10;
		while(n){
			const int t=n%10;
			n/=10;
			if(t<ans)
				ans=t;
		}
		putchar(ans|'0');
		putchar('\n');
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}