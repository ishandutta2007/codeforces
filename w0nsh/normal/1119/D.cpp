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
typedef std::pair<long long, long long> PLL;
typedef std::vector<int> VI;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<ll> s(n), A;
	FOR(i, n) std::cin >> s[i];
	std::sort(s.begin(), s.end());
	FOR(i, n-1) A.push_back(s[i+1]-s[i]);
	std::sort(A.begin(), A.end(), std::greater<long long>());
	std::vector< PR<PR<long long, int>, PLL> > queries;
	int q;
	std::cin >> q;
	FOR(i, q){
		long long a, b;
		std::cin >> a >> b;
		queries.push_back(MP(MP(b-a, i), MP(a, b)));
	}
	std::sort(queries.begin(), queries.end());
	std::vector<ll> ans(q);
	ll add = 0;
	ll ile = n;
	TRAV(qr, queries){
		while(!A.empty() && A.back() <= qr.X.X){
			ile--;
			add += A.back();
			A.pop_back();
		}
		ans[qr.X.Y] = ile*(qr.Y.Y-qr.Y.X+1) + add;
	}
	FOR(i, q) std::cout << ans[i] << " ";
	return 0;
}