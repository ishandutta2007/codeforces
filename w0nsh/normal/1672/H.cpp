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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;
	std::vector<BIT<int>> bit(2, BIT<int>(n+5));
	FOR(i, n-1){
		if(s[i] == s[i+1]){
			bit[s[i]-'0'].add(i+1, 1);
		}
	}

	FOR(_, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		int mx = 0;
		FOR(i, 2){
			int cur = bit[i].query(b) - bit[i].query(a);
			mx = std::max(mx, cur);
		}
		std::cout << mx+1 << "\n";
	}

	return 0;
}