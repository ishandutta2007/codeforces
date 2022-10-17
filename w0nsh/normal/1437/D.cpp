#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::queue<int> que;
	que.push(0);
	int mx = 0;
	int pos = 1;
	while(pos < n){
		int par = que.front();
		que.pop();
		mx = std::max(mx, par+1);
		int ile = 1;
		while(pos < n-1 && A[pos] < A[pos+1]) ile++, pos++;
		pos++;
		FOR(i, ile) que.push(par+1);
	}
	std::cout << mx << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}