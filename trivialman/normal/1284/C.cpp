#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
//const LL P = 1e9+7;
LL P = 1e9+7;
const int N = 3e5+5;
mt19937 rng(time(0));

LL fac[N];
int n;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>P;
	fac[0] = 1;
	rep(i,1,n) fac[i] = fac[i-1] * i % P;
	LL ans = 0;
	rep(i,1,n){
		LL x = n - i + 1;
		(ans += x * x % P * fac[i] % P * fac[n-i] % P) %= P;
	}
	cout<<ans<<endl;
	return 0;
}