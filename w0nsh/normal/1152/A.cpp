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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	int a[2], b[2];
	a[0] = a[1] = b[0] = b[1] = 0;
	FOR(i, n){
		int x;
		std::cin >> x;
		a[x%2]++;
	}
	FOR(i, m){
		int x;
		std::cin >> x;
		b[x%2]++;
	}
	std::cout << std::min(b[1], a[0]) + std::min(a[1], b[0]);
	return 0;
}