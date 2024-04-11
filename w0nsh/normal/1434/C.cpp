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

ll ary(ll mx, ll n){
	return mx*n/2;
}

void solve(ll a, ll b, ll c, ll d){
	if(b*c < a){
		std::cout << -1 << "\n";
		return;
	}
	if(d >= c){
		std::cout << a << "\n";
		return;
	}

	ll ans = a;

	auto get = [&](ll m){
		ll ret = a*m;

		ll tim = (m-1)*d;
		ll upto = tim-c;
		ll x = upto/d + 1;
		if(upto < 0){
			x = 0;
		}
		ret -= x*c*b; // overflow

		ll zost = m-x;
		assert(zost >= 0);
		ret -= ary(d*b*(zost-1), zost);

		ans = std::max(ans, ret);
		return ret;
	};

	ll left = 1;
	ll right = 2000005; // 10^6 ?
	while(left <= right){
		ll mid = (left+right)/2;
		if(get(mid) < get(mid+1)){
			left = mid+1;
		}else{
			right = mid-1;
		}
	}
	
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		solve(a, b, c, d);
	}

	return 0;
}