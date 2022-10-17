#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int N = 1000006;
std::vector<bool> prime;

ll get(VI A){
	int n = SZ(A);
	VI lef(n);
	VI rig(n);
	FOR(i, n){
		lef[i] = (i == 0 ? 0 : lef[i-1]);
		if(A[i] == 1) lef[i]++;
		else lef[i] = 0;
	}

	for(int i = n-1; i >= 0; --i){
		rig[i] = (i == n-1 ? 0 : rig[i+1]);
		if(A[i] == 1) rig[i]++;
		else rig[i] = 0;
	}

	ll ret = 0;
	FOR(i, n){
		if(prime[A[i]]){
			ret += 1ll * (i == 0 ? 1 : (lef[i-1] + 1)) * (i == n-1 ? 1 : (rig[i+1] + 1));
			ret--;
		}
	}
	return ret;
}

void solve(){
	int n, e;
	std::cin >> n >> e;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	ll ans = 0;
	FOR(start, e){
		VI heh;
		int pos = start;
		while(pos < n){
			heh.push_back(A[pos]);
			pos += e;
		}

		ans += get(heh);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	prime.resize(N, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i < N; ++i){
		if(prime[i]){
			for(int j = 2*i; j < N; j += i){
				prime[j] = false;
			}
		}
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}