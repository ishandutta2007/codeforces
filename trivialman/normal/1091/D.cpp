#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

LL n,ans=0,fac=1;


int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	cin>>n;
	for(LL i=n;i>2;--i){
		fac = fac * i % MOD;
		ans = (ans - fac + MOD) % MOD;
	}
	fac = fac * 2 % MOD;
	ans = (ans + fac * (n-1)) % MOD;
	cout<<(n==1?1:ans)<<endl;
	return 0;
}