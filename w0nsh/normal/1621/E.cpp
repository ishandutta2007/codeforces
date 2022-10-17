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

typedef long double K;
constexpr K eps = 1e-10;

void solve(){
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	std::reverse(A.begin(), A.end());
	A.resize(m);
	std::reverse(A.begin(), A.end());

	std::vector<PR<VI, PR<ll, int>>> B(m);
	FOR(i, m){
		int k;
		std::cin >> k;
		B[i].X.resize(k);
		FOR(j, k) std::cin >> B[i].X[j], B[i].Y.X += B[i].X[j];
		B[i].Y.Y = i;
	}


	auto sr = [&](ll sm, int ile){
		return static_cast<K>(sm) / ile;
	};

	std::sort(B.begin(), B.end(), [&](const auto &a, const auto& b){
		return sr(a.Y.X, SZ(a.X)) < sr(b.Y.X, SZ(b.X));
	});

	std::set<int> shift[3];
	FOR(s, 3){
		int ss = s-1;
		FOR(i, m){
			int kt = i+ss;
			if(kt < 0 || kt >= m || sr(B[i].Y.X, SZ(B[i].X)) <= A[kt] + eps){

			}else{
				shift[s].insert(i);
			}
		}
	}

	std::vector<VI> ans(m);

	auto miedzy = [&](std::set<int>& set, int a, int b){
		if(a > b) return false;
		auto it = set.lower_bound(a);
		if(it != set.end() && *it <= b) return true;
		return false;
	};

	FOR(i, m){
		TRAV(x, B[i].X){
			ll sm = B[i].Y.X - x;
			K nw = sr(sm, SZ(B[i].X)-1);
			int good = 1;

			int left = 0;
			int right = m;
			while(left < right){
				int mid = (left+right)/2;
				if(sr(B[mid].Y.X, SZ(B[mid].X)) < nw){
					left = mid+1;
				}else{
					right = mid;
				}
			}

			if(left > i){
				left--;
				if(nw > A[left] + eps){
					good = 0;
				}
				if(miedzy(shift[1], 0, i-1)) good = 0;
				if(miedzy(shift[1], left+1, m-1)) good = 0;
				if(miedzy(shift[0], i+1, left)) good = 0;
			}else if(left < i){
				if(nw > A[left] + eps){
					good = 0;
				}
				if(miedzy(shift[1], 0, left-1)) good = 0;
				if(miedzy(shift[1], i+1, m-1)) good = 0;
				if(miedzy(shift[2], left, i-1)) good = 0;
			}else{
				if(nw > A[left] + eps){
					good = 0;
				}
				if(miedzy(shift[1], 0, i-1)) good = 0;
				if(miedzy(shift[1], i+1, m-1)) good = 0;
			}

			ans[i].push_back(good);
		}
	}

	VI where(m);
	FOR(i, m) where[B[i].Y.Y] = i;
	FOR(i, m){
		int ind = where[i];
		FOR(j, SZ(B[ind].X)){
			std::cout << ans[ind][j];
		}
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