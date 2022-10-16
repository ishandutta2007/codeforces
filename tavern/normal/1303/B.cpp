#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const ll INF = 2e18;

inline ll check(ll md, ll g, ll b){
	ll ret =  md / (g + b) * g;
	ll rem = md % (g + b);
	return ret + min(g, rem);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		ll n, g, b;
		scanf("%lld%lld%lld", &n, &g, &b);
		ll lb = 0, rb = INF;
		for(; lb + 1 < rb; ){
			ll md = lb + rb >> 1;
			if(check(md, g, b) >= (n + 1) / 2)
				rb = md;
			else
				lb = md;
		}
		printf("%lld\n", max(rb, n));
	}
	return 0;
}