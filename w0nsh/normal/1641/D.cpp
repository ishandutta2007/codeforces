#pragma GCC optimize "O3"
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

template<int N>
class Bitset{
public:
	uint64_t t[N / 64];

	Bitset() {
		FOR(i, N / 64) t[i] = 0;
	}

	void or_with(const Bitset<N>& a){
		FOR(i, N / 64) t[i] |= a.t[i];
	}

	void set(int co){
		t[co / 64] |= (static_cast<uint64_t>(1) << (co % 64));
	}

	int first() const {
		static constexpr uint64_t FULL = static_cast<uint64_t>(-1);
		FOR(i, N / 64){
			if(t[i] != FULL){
				FOR(j, 64) if(!(t[i] & (static_cast<uint64_t>(1) << j))) return i * 64 + j;
			}
		}
		return -1;
	}
};

constexpr int MAX = 100096;
constexpr int THRESH = 500;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::map<int, int> cnt;
	std::map<int, Bitset<MAX>> map;
	std::vector<PR<int, VI>> A(n, MP(0, VI(m)));
	std::map<int, VI> where;
	VI W(n);
	FOR(i, n){
		FOR(j, m) std::cin >> A[i].Y[j];
		FOR(j, m) cnt[A[i].Y[j]]++;
		std::cin >> A[i].X;
	}

	std::sort(A.begin(), A.end());

	FOR(i, n){
		FOR(j, m){
			if(cnt[A[i].Y[j]] > THRESH){
				auto& my = map[A[i].Y[j]];
				my.set(i);
			}else{
				where[A[i].Y[j]].push_back(i);
			}
		}
	}

	constexpr int INF = 1000000000 * 2 + 5;
	int ans = INF;

	// FOR(i, n) std::cout << A[i].X << " ";
	// std::cout << "\n";

	FOR(i, n){
		Bitset<MAX> bs;
		bs.set(i);

		// std::cout << "teraz " << i << std::endl;

		FOR(j, m){
			auto it = map.find(A[i].Y[j]);
			if(it != map.end()){
				bs.or_with(it->Y);
			}else{
				TRAV(k, where[A[i].Y[j]]){
					// std::cout << "blok " << k << std::endl;
					bs.set(k);
				}
			}
		}

		int kt = bs.first();
		// std::cout << "first " << kt << std::endl;
		if(kt != -1 && kt < n){
			ans = std::min(ans, A[i].X + A[kt].X);
		}
	}

	std::cout << (ans == INF ? -1 : ans) << "\n";

	return 0;
}