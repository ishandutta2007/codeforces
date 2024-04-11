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

const int N = 200005;
int n, k, q;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> q;
	VI A(N);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		A[a] += 1;
		A[b+1] -= 1;
	}
	int have = 0;
	FOR(i, N){
		have += A[i];
		if(have >= k) A[i] = 1;
		else A[i] = 0;
	}
	VI pref(N+1);
	REP(i, 1, N+1) pref[i] = pref[i-1] + A[i-1];  
	FOR(_, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		std::cout << pref[b+1]-pref[a] << "\n";
	}
	return 0;
}