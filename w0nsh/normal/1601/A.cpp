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

std::vector<VI> divs;

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	int ret = 0;
	FOR(b, 30){
		int cnt = 0;
		FOR(i, n) if(A[i] & (1<<b)) cnt++;
		if(cnt) ret = std::gcd(ret, cnt);
	}

	if(ret == 0){
		FOR(i, n) std::cout << i+1 << " ";
	}else{
		TRAV(i, divs[ret]) std::cout << i << " ";
	}
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	divs.resize(200002);
	for(int i = 1; i <= 200001; ++i){
		for(int j = i; j <= 200001; j += i){
			divs[j].push_back(i);
		}
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}