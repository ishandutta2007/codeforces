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

constexpr ll MAX = 1000000000ll*100ll;
std::vector<ll> fib;

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	ll sum = 0;
	FOR(i, n) std::cin >> A[i], sum += A[i];

	int ile = 0;
	ll have = 0;
	while(have < sum){
		have += fib[ile++];
	}
	if(have > sum){
		std::cout << "NO\n";
		return;
	}

	bool good = false;

	auto check = [&](){
		ll rr = 0;
		int ind = 0;
		auto B = A;
		TRAV(x, B){
			ind++;
			// std::cout << "teraz " << x << std::endl;
			int last = 1000000666;
			for(int i = ile-1; i >= 1; --i){
				if(fib[i] <= x){
					if (rr & (1ll<<i)){
						return false;
					}
					if(i == 1 && ind == n){
						return false;
					}
					if(last == i+1){
						return false;
					}
					x -= fib[i];
					// std::cout << "dod " << fib[i] << std::endl;
					rr |= (1ll<<i);
					last = i;
				}
			}
			if(x != 0){
				return false;
			}
		}
		return true;
	};

	FOR(i, n){
		std::rotate(A.begin(), A.begin() + 1, A.end());
		A.back() -= 1;
		if(check()) good = true;
		A.back() += 1;
	}

	std::cout << (good ? "YES\n" : "NO\n");
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	fib.push_back(1);
	fib.push_back(1);
	while(fib.back() <= MAX){
		fib.push_back(fib[SZ(fib)-2] + fib[SZ(fib)-1]);
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}