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

constexpr int MAX = 3 * 100000 + 666;

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
	T sum(int a, int b){
		return query(b) - query(a-1);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	constexpr int THRESH = 500;

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	ll ans = 0;

	BIT<int> count(MAX);
	BIT<ll> vals(MAX);

	ll allsum = 0;
	auto add = [&](int val, int k){
		// x mod val
		if (val < THRESH){
			FOR(i, k) {
				ans += A[i] % val;
			}
		}else{
			ans += allsum;
			FOR(ile, (MAX / val)+2){
				int pocz = ile * val;
				int kon = (ile + 1) * val - 1;
				pocz = std::min(pocz, MAX-1);
				kon = std::min(kon, MAX-1);
				ans -= 1ll * ile * val * count.sum(pocz, kon);
			}
		}

		// val mod x
		int dv = 1;
		while(dv <= val){
			int ile = val / dv;
			int next = (val / ile) + 1;

			// assert(next > dv);
			int upto = next-1;

			// (dv, upto)
			ans -= 1ll * ile * vals.sum(dv, upto);

			dv = next;
		}

		// assert(dv == val+1);
		ans += 1ll * val * k;

		count.add(val, 1);
		vals.add(val, val);
		allsum += val;
	};

	FOR(i, n){
		add(A[i], i);
		std::cout << ans << " ";
	}

	return 0;
}