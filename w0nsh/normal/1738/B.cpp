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

ll cl(ll a, ll b){
	if(a < 0){
		a *= -1;
		return -(a / b);
	}else{
		return (a + b - 1) / b;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, k;
		std::cin >> n >> k;
		VI P(n);
		FOR(i, k) std::cin >> P[n - k + i];
		if(k == 1){
			std::cout << "Yes\n";
			continue;
		}

		VI A(n);
		REP(i, n - k + 1, n){
			A[i] = P[i] - P[i-1];
		}
		bool bad = false;
		REP(i, n - k + 2, n){
			if(A[i] < A[i-1]){
				bad = true;
			}
		}
		ll sum = P[n-k];
		ll mn = A[n-k+1];
		ll left = n-k+1;
		if(cl(sum, left) > mn){
			bad = true;
		}

		if(bad) std::cout << "No\n";
		else std::cout << "Yes\n";
	}

	return 0;
}