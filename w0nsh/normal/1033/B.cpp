#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

ll a, b;

bool is_prime(ll n){
	for(int i = 2; 1ll*i*i <= n; ++i){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> a >> b;
		if((a-b) == 1 && is_prime(a+b)) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}