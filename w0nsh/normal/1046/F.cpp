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

int n, x, f, A[200000], ans;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) std::cin >> A[i];
	std::cin >> x >> f;
	ll cnt = 0;
	FOR(i, n) if(A[i] > x){
		int ile = (A[i]-x)/(x+f);
		cnt += ile;
		A[i] -= (x+f)*ile;
		if(A[i] > x) cnt++;
	}
	std::cout << cnt*f << "\n";
	return 0;
}