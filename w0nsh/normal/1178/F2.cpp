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



const int INF = 2000000666;

struct MinTree{
	int BOTTOM;
	VI t, vec;
	inline int left(int a){
		return a<<1;
	}
	inline int right(int a){
		return (a<<1)+1;
	}
	inline int parent(int a){
		return a>>1;
	}
	void prop(int v){
		if(v >= BOTTOM) return;
		prop(left(v));
		prop(right(v));
		if(vec[t[left(v)]] < vec[t[right(v)]]) t[v] = t[left(v)];
		else t[v] = t[right(v)];
	}
	void build(VI vc){
		int size = SZ(vc);
		vec = vc;
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM *= 2;
		}
		t.resize(BOTTOM*2);
		FOR(i, size) t[i+BOTTOM] = i;
		REP(i, size, BOTTOM) t[i+BOTTOM] = -1;
		prop(1);
	}
	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int mn = -1;
		while(a < b){
			if(a&1){
				if(t[a] != -1 && (mn == -1 || vec[mn] > vec[t[a]])) mn = t[a];
				a++;
			}
			if(b&1){
				--b;
				if(t[b] != -1 && (mn == -1 || vec[mn] > vec[t[b]])) mn = t[b];
			}
			b >>= 1; a >>= 1;
		}
		return mn;

		// if(hi==-2) hi = BOTTOM-1;
		// if(a > b) return -1;
		// if(a == lo && b == hi) return t[v];
		// int mid = (lo+hi)/2;
		// int l = query(a, std::min(b, mid), left(v), lo, mid);
		// int r = query(std::max(a, mid+1), b, right(v), mid+1, hi);
		// if(r == -1) return l;
		// if(l == -1) return r;
		// if(vec[l] < vec[r]) return l;
		// return r;
	}
};

const int MOD = 998244353;
int n, m;
VI A;
MinTree tree;
std::unordered_map<ll, int> dp;
VI guys[505];

int fguy(int a, int b, int what){
	return *std::lower_bound(guys[what].begin(), guys[what].end(), a);
}
int lguy(int a, int b, int what){
	return *std::next(std::lower_bound(guys[what].begin(), guys[what].end(), b+1), -1);
}

int solve(int a, int b){
	ll id = 1000000000ll*a+b;
	if(a >= b) return 1;
	if(dp.find(id) != dp.end()) return dp[id];
	// std::cout << a << " " << b << std::endl;
	int pos = tree.query(a, b);
	int guy = A[pos];

	auto it = guys[guy].begin();

	int left = *it;
	int right = left;

	int ans = 1;

	int last = left;
	while(true){
		// if(guy == 2){
			// std::cout << "now at " << *it << std::endl;
		// }
		it++;
		if(it == guys[guy].end()) break;
		right = *it;
		if(right - last > 2){
			ans = (1ll*ans*solve(last+1, right-1))%MOD;
			// if(guy == 2){
				// std::cout << "solving " << last+1 << " " << right-1 << std::endl;
				// std::cout << solve(last+1, right-1) << "\n";
			// }
		}
		last = right;
	}

	int l = solve(a, left-1);
	int g = left-1;
	while(g >= a){
		l = (l+((1ll*solve(a, g)*solve(g+1, left-1))%MOD))%MOD;
		g = fguy(a, left, A[g])-1;
	}

	int r = solve(right+1, b);
	g = right+1;
	while(g <= b){
		r = (r+((1ll*solve(right+1, g-1)*solve(g, b))%MOD))%MOD;
		g = lguy(right, b, A[g])+1;	
	}

	// if(guy == 1){
	// 	std::cout << 1 << ":";
	// 	std::cout << l << " " << r << " " << ans << "\n";
	// }


	// if(guy == 2){
	// 	std::cout << 2 << ":";
	// 	std::cout << l << " " << r << " " << ans << "\n";
	// }
	// std::cout << l << " " << r << std::endl;

	// REP(i, a, pos+1) l = (l+((1ll*solve(a, i-1)*solve(i, pos-1))%MOD))%MOD;
	// REP(i, pos, b+1) r = (r+((1ll*solve(pos+1, i)*solve(i+1, b))%MOD))%MOD;

	dp[id] = (1ll*l*r)%MOD;
	dp[id] = (1ll*dp[id]*ans)%MOD;
	return dp[id];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(m);
	FOR(i, m) std::cin >> A[i];
	FOR(i, m) guys[A[i]].push_back(i);
	tree.build(A);
	REP(i, 1, n+1){
		int mn = tree.query(fguy(0, m-1, i), lguy(0, m-1, i));
		if(A[mn] < i){
			std::cout << 0;
			return 0;
		}
	}
	std::cout << solve(0, m-1);
	return 0;
}