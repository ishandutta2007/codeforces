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

std::map<int, int> map;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	map[4] = 1;
	map[8] = 2;
	map[15] = 3;
	map[16] = 4;
	map[23] = 5;
	map[42] = 6;
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i] = map[A[i]];
	int cur = 0;
	int ans = 0;
	int have[7];
	FOR(i, 7) have[i] = 0;
	have[0] = 1000000000;
	FOR(i, n){
		if(have[A[i]-1] > 0){
			have[A[i]]++;
			have[A[i]-1]--;
		}else ans++;
	}
	REP(i, 1, 6) ans += have[i]*i;
	std::cout << ans;
	return 0;
}