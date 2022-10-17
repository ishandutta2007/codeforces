#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	VI podz(n, 1);

	std::priority_queue<PR<ll, int> > que;
	auto wyn = [&](int a, int ile){
		if(a%ile == 0){
			return 1ll*ile*(a/ile)*(a/ile);
		}
		int big = a%ile;
		int small = ile-big;
		int b = a/ile+1;
		int s = a/ile;
		return 1ll*big*b*b + 1ll*small*s*s;
	};

	auto better = [&](int a, int ile){
		return wyn(a, ile) - wyn(a, ile+1);
	};

	FOR(i, n){
		que.push(MP(better(A[i], podz[i]), i));
	}

	FOR(_, k-n){
		int v = que.top().Y;
		que.pop();
		podz[v]++;
		que.push(MP(better(A[v], podz[v]), v));
	}

	ll ans = 0;
	FOR(i, n) ans += wyn(A[i], podz[i]);
	std::cout << ans << "\n";

	return 0;
}