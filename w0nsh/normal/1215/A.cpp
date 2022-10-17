#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int mx(int a1, int a2, int k1, int k2, int n){
		int max = 0;
	while(a1 > 0 && n >= k1){
		max++;
		n -= k1;
		a1--;
	}
	while(a2 > 0 && n >= k2){
		max++;
		n -= k2;
		a2--;
	}
	return max;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int a1, a2, k1, k2, n;
	std::cin >> a1 >> a2 >> k1 >> k2 >> n;
	if(k1 > k2){
		std::swap(a1, a2);
		std::swap(k1, k2);
	}
	int max = mx(a1, a2, k1, k2, n);
	FOR(i, a1) n -= k1-1;
	FOR(i, a2) n -= k2-1;
	std::cout << std::max(0, n) << " " << max << "\n";
	return 0;
}