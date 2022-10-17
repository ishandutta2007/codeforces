#include <bits/stdc++.h>
#define ll long long
#define FOR(i, n) for(int i =0; i  < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define PR std::pair
#define PII std::pair<int, int>
#define SZ(i) ((int)((i).size()))
#define VI std::vector<int>
#define MP std::make_pair
#define X first
#define Y second

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<ll> A(n);
	FOR(i, n) std::cin >> A[i];
	ll have = 0;
	int pos = 0;
	FOR(i, m){
		ll cur;
		std::cin >> cur;
		while(pos < n && have + A[pos] < cur) have += A[pos++];
		std::cout << pos+1 << " " << cur-have << "\n";
	}
	return 0;
}