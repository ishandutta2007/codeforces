#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}

	FOR(i, n){
		A[i] = (i+1)-A[i];
		if(A[i] < 0) A[i] = -1;
		else{
			assert(A[i] <= n-1);
		}
	}

	std::vector<std::vector<PII> > que(n);

	FOR(i, q){
		int x, y;
		std::cin >> x >> y;
		y = n-1-y;
		assert(y >= 0 && y < n);
		que[y].push_back(MP(x, i));
	}

	BIT<int> bit(n+5);

	auto add = [&](int i){
		if(A[i] > -1){
			int left = 0;
			int right = i+1;
			while(left < right){
				int mid = (left+right)/2;
				if(bit.query(mid) >= A[i]) left = mid+1;
				else right = mid;
			}
			bit.add(0, 1);
			bit.add(left, -1);
		}

	};

	auto query = [&](int i){
		return bit.query(i);
	};

	VI ans(q);
	FOR(i, n){
		add(i);
		TRAV(pr, que[i]){
			ans[pr.Y] = query(pr.X);
		}
	}

	FOR(i, q) std::cout << ans[i] << "\n";


	return 0;
}