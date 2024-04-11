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

const int INF = 1000000666;

VI sum[102][102];
int pref[102][200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	VI cnt(105);
	FOR(i, n) std::cin >> A[i], A[i]--, cnt[A[i]]++;

	std::vector<VI> B(100);
	FOR(i, 100) B[i].reserve(cnt[i]+2);
	FOR(i, n) B[A[i]].push_back(i);
	FOR(i, 100){
		REP(j, 1, n+1){
			pref[i][j] = pref[i][j-1];
			if(A[j-1] == i) pref[i][j]++;
		}
	}

	FOR(i, 100){
		FOR(j, 100){
			if(i == j) continue;
			auto& a = B[i];
			auto& b = B[j];

			auto it = a.begin();
			auto jt = b.begin();
			auto& vec = sum[i][j];
			vec.reserve(SZ(a) + SZ(b) + 5);
			int sm = 0;
			vec.push_back(0);
			int ind = 0;
			while(it != a.end() || jt != b.end()){
				int kto = 1;
				if(it == a.end()) kto = -1;
				else if(jt != b.end() && *it > *jt) kto = -1;
				sm += kto;
				if(kto == 1) ind = *it, it++;
				else ind = *jt, jt++;
				if(sm >= SZ(vec)){
					vec.push_back(ind);
				}
			}
		}
	}

	int ans = 0;
	FOR(i, n){
		PII best = MP(-1, -1);
		int who = -1;
		FOR(j, 100){
			if(pref[j][i+1] > best.X){
				who = j;
				best.X = pref[j][i+1];
				best.Y = 1;
			}else if(pref[j][i+1] == best.X){
				best.Y++;
			}
		}
		assert(best.X >= 1);
		if(best.Y > 1){
			ans = i+1;
			continue;
		}

		assert(who != -1);
		int min = 1000000000;
		FOR(j, 100){
			if(j == who) continue;
			int roz = pref[who][i+1] - pref[j][i+1];
			assert(roz > 0);

			if(SZ(sum[who][j]) <= roz) continue;
			min = std::min(min, sum[who][j][roz]);
		}
		ans = std::max(ans, i-min); // +1 ?
	}

	std::cout << ans << "\n";

	return 0;
}