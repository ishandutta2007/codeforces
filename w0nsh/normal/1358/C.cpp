#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

#define ll __int128

ll ar(ll a, ll b, ll n){
	return (a+b)*n/2;
}

ll war(ll x, ll y){
	ll p = x+y-2;
	return ar(1, p, p) + x;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;

	while(t--){
		int a1, a2, a3, a4;
		std::cin >> a1 >> a2 >> a3 >> a4;
		ll x1 = a1;
		ll y1 = a2;
		ll x2 = a3;
		ll y2 = a4;

		ll w = war(x1, y1);
		ll e = war(x2, y2);
		
		ll rig = war(x1, y2);
		ll small = ar(w, rig, y2-y1+1);
		small += ar(rig, e, x2-x1+1);
		small -= rig;


		ll dow = war(x2, y1);
		ll big = ar(w, dow, x2-x1+1);
		big += ar(dow, e, y2-y1+1);
		big -= dow;

		std::cout << (long long )(big-small+1) << "\n";
		
	}

	return 0;
}