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

constexpr int N = 100005;
constexpr int SQ = 400;
constexpr int UP = N / SQ + 10;

constexpr int MN = N + 2;
std::map<int, int> map[UP];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	int ans = 1;

	VI B;
	REP(d, -SQ, SQ){
		B = A;
		FOR(i, n) B[i] += d*i;
		std::sort(B.begin(), B.end());
		int cnt = 1;
		REP(i, 1, n){
			if(B[i] == B[i-1]){
				cnt++;
				if(cnt > ans) ans = cnt;
			}
			else cnt = 1;
		}
	}

	FOR(i, n){
		int ind = i%UP;
		map[ind].clear();

		for(int j = i-1; j >= 0; --j){
			int up = A[i] - A[j];
			int down = i - j;
			if(down >= UP) break;

			if(up % down != 0) continue;
			int d = up / down;
			if(std::abs(d) < SQ) continue;

			int jnd = j % UP;
			int& val = map[ind][d];
			auto it = map[jnd].find(d);

			if(val < 2) val = 2;
			if(it != map[jnd].end()){
				val = std::max(val, it->Y + 1);
			}

			if(val > ans) ans = val;
		}
	}

	std::cout << n - ans << "\n";

	return 0;
}