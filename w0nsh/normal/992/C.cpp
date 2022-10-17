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

const int MOD = 1000000007;
ll n, k;

int fast_pow(int a, ll e){
	if(e == 0) return 1;
	if(e == 1) return a%MOD;
	int t = fast_pow(a, e/2);
	t = (1ll*t*t)%MOD;
	if(e%2 == 1) t = (1ll*t*a)%MOD;
	return t;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	if(n == 0){
		std::cout << 0 << "\n";
		return 0;
	}
	if(k == 0){
		std::cout << (2ll*n)%MOD << "\n";
		return 0;
	}
	int xd = (1ll*(n%MOD)*fast_pow(2, k))%MOD;
	xd -= fast_pow(2, k-1)-1;
	while(xd < 0) xd += MOD;
	xd = (2ll*xd)%MOD;
	xd--;
	if(xd < 0) xd += MOD;
	std::cout << xd << "\n";
	return 0;
}