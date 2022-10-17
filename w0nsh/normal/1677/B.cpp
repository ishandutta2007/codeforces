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

	void add(int a, int b, T val){
		add(a, val);
		add(b + 1, -val);
	}
};

void solve(){
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;

	int ans = 0;
	VI col(m);
	int ind = 0;
	BIT<int> bit(m + 5);
	int prev = -1000000000;
	TRAV(c, s){
		if(c == '1'){
			if(col[ind % m] == 0){
				col[ind % m] = 1;
				ans++;
			}
			int dst = ind - prev;
			if(dst >= m){
				bit.add(0, m-1, 1);
			}else{
				int fs = (prev + m) % m;
				int ls = (ind + m - 1) % m;
				if(fs <= ls) {
					bit.add(fs, ls, 1);
				}else{
					bit.add(0, ls, 1);
					bit.add(fs, m-1, 1);
				}
			}
			prev = ind;
		}

		std::cout << ans + bit.query(ind % m) << " ";

		ind++;
	}
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}