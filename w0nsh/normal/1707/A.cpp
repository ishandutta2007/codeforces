#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n, q;
	std::cin >> n >> q;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	int kt = 0;
	int ans = 0;
	std::string s;
	FOR(i, n) s.push_back('0');
	for(int i = n-1; i >= 0; --i){
		if(A[i] <= kt){
			ans++;
			s[i] = '1';
		}else{
			if(kt < q){
				kt++;
				s[i] = '1';
				ans++;
			}
		}
	}
	std::cout << s << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}