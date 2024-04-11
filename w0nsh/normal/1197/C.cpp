#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
typedef double ld;

int n;
ll k;
ll A[300005];

PR<ll, int> check(ll p){
	PR<ll, int> best = MP(-A[1], 0);
	REP(i, 1, n){
		PR<ll, int> cur = best;
		cur.X += A[i]+p;
		cur.Y++;
		best = std::min(best, MP(cur.X-A[i+1], cur.Y));
	}
	return MP(best.X+A[n]+p, best.Y+1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	REP(i, 1, n+1) std::cin >> A[i];
	ll left = 0;
	ll right = 1e9+5;
	while(left < right){
		ll mid = (left+right)/2;
		if(check(mid).Y > k) left = mid+1;
		else right = mid;
	}
	//std::cout << left << " " << check(left).Y << std::endl;
	std::cout << check(left).X - left*k << "\n";
	return 0;
}