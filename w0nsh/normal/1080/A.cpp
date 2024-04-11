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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, k;
	std::cin >> n >> k;
	ll red = n*2;
	ll green = n*5;
	ll blue = n*8;
	std::cout << red/k + green/k + blue/k + (red%k == 0 ? 0 : 1) + (green%k == 0 ? 0 : 1) + (blue%k == 0 ? 0 : 1);
	return 0;
}