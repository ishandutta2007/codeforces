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

template<class T>
struct BIT{
	std::vector<T> t;
	inline int LSB(int a){ return a&(-a); }
	BIT(){}
	BIT(int sz){ t.resize(sz+1); }
	void add(int x, T val){
		x++;
		while(x < (int)t.size()) t[x] += val, x += LSB(x); // change operation here
	}
	T query(int x){
		x++;
		T r = 0;
		while(x > 0) r += t[x], x -= LSB(x); // change operation here
		return r;
	}
};

void solve(){
	int n;
	std::cin >> n;
	std::string A, B;
	std::cin >> A >> B;

	BIT<int> bit(n+5);
	FOR(i, n) bit.add(i, 1);
	constexpr int C = 26;

	std::vector<VI> vec(C, VI());
	FOR(i, n) vec[A[i]-'a'].push_back(i);
	FOR(i, C) std::reverse(vec[i].begin(), vec[i].end());

	constexpr ll INF = 1000000000ll*1000000000ll;
	constexpr int N = 1000000666;
	ll best = INF;
	ll have = 0;

	TRAV(c, B){
		int kt = c-'a';

		int mn = N;
		int ind = -1;
		FOR(ch, kt){
			if(!vec[ch].empty() && vec[ch].back() < mn){
				mn = vec[ch].back();
				ind = ch;
			}
		}
		if(ind != -1){
			int ile = bit.query(mn) - 1;
			best = std::min(best, have + ile);
		}

		if(!vec[kt].empty()){
			ind = vec[kt].back();
			vec[kt].pop_back();
			int ile = bit.query(ind) - 1;
			have += ile;
			bit.add(ind, -1);
		}else{
			break;
		}
	}

	std::cout << (best == INF ? -1 : best) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}