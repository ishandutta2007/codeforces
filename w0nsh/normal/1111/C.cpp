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

int n, k, A, B;
std::vector<PII> pref;
std::map<int, int> map;

int sum(int a, int b){
	auto lf = std::lower_bound(pref.begin(), pref.end(), MP(a, -1));
	lf--;
	auto rg = std::upper_bound(pref.begin(), pref.end(), MP(b, 1000000000));
	rg--;
	return rg->Y - lf->Y;
}

ll answer(int a, int b){
	if(sum(a, b) == 0) return A;
	if(a == b) return 1ll*B*sum(a, b);
	int mid = (a+b)/2;
	return std::min(1ll*B*sum(a, b)*(b-a+1), answer(a, mid)+answer(mid+1, b));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> A >> B;
	n = 1<<n;
	FOR(i, k){
		int a;
		std::cin >> a;
		a--;
		map[a]++;
	}
	pref.push_back(MP(-1, 0));
	TRAV(pr, map) pref.push_back(MP(pr.X, pref.back().Y + pr.Y));
	pref.push_back(MP(n, pref.back().Y));
	std::cout << answer(0, n-1) << "\n";
	return 0;
}