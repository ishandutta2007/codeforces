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

ll ar(ll a, ll b, ll n){
	return (a+b)*n/2;
}

ll solve(ll n, ll k, VI A, bool rev){
	std::vector<ll> pref(3*n+1), values(3*n+1);
	pref[0] = 0;
	values[0] = 0;
	for(int i = 1; i <= 3*n; ++i) pref[i] = A[i-1]+pref[i-1];
	for(int i = 1; i <= 3*n; ++i){
		values[i] = values[i-1] + 1ll*A[i-1]*(A[i-1]+1)/2;
	}

	auto sum = [&](int a, int b){
		return pref[b+1]-pref[a];
	};

	auto sum_values = [&](int a, int b){
		return values[b+1]-values[a];
	};

	ll ret = 0;
	for(int s = 0; s < n; ++s){
		
		int left = s-1;
		int right = 3*n;

		while(left < right){
			int mid = (left+right)/2;
if(left == -1 && right == 0) mid = -1;

			if(sum(s, mid) <= k) left = mid+1;
			else right = mid;
		}

		left--;
		ll cand = sum_values(s, left);
		ll zost = k-sum(s, left);
		assert(zost < A[left+1]);
		if(zost > 0){
			if(rev) cand += ar(A[left+1]-zost+1, A[left+1], zost);
			else cand += zost*(zost+1)/2;
		}

		ret = std::max(ret, cand);

	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, k;
	std::cin >> n >> k;

	VI A(3*n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, 2*n) A[i+n] = A[i];

	ll ans = solve(n, k, A, false);
	std::reverse(A.begin(), A.end());
	ans = std::max(ans, solve(n, k, A, true));
	std::cout << ans << "\n";

	return 0;
}