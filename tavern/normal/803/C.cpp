//orz dxm
#include<bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll ans = -1;
ll n, k;

int main(){
	scanf("%lld%lld", &n, &k);
	if(k >= 1e9){
		puts("-1");
		return 0;
	}
	ll s = (k + 1) * k / 2;
	for(ll i = 1; 1ll * i * i <= n; ++i){
		if(n % i == 0){
			if(s <= n / i) ans = max(ans, i);
			if(s <= n / (n / i)) ans = max(ans, n / i);
		}
	}
	if(!~ans){
		puts("-1");
		return 0;
	}
	REP(i, 1, k){
		ll res = ans;
		if(i != k) res *= i;
		else res *= (n / ans - s + i);
		printf("%lld%c", res, (i == k) ? '\n' : ' ');
	}
	return 0;
}