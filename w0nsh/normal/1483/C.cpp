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

constexpr ll INF = 1000000666ll*1000000000ll;
struct Tree{
	int BOTTOM;
	std::vector<ll> t;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = std::vector<ll>(BOTTOM*2, -INF);
	}

	void set(int v, ll val){
		v += BOTTOM;
		t[v] = val;
		v /= 2;
		while(v >= 1){
			t[v] = std::max(t[v<<1], t[(v<<1)+1]);
			v /= 2;
		}
	}

	ll query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		ll mx = -INF;
		while(a < b){
			if(a&1) mx = std::max(mx, t[a++]);
			if(b&1) mx = std::max(mx, t[--b]);
			a>>=1;b>>=1;
		}
		return mx;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<ll> H(n+1), B(n+1);
	FOR(i, n) std::cin >> H[i+1];
	FOR(i, n) std::cin >> B[i+1];
	Tree tree;
	tree.build(n+1);
	tree.set(0, 0);
	std::vector<PR<ll, int>> stack;
	stack.push_back(MP(0ll, 0));
	std::multiset<ll> mam;
	REP(i, 1, n+1){
		while(stack.back().X > H[i]){
			ll val = tree.query(stack[SZ(stack)-2].Y, stack.back().Y-1);
			val += B[stack.back().Y];
			auto xd = mam.find(val);
			assert(xd != mam.end());
			mam.erase(xd);
			stack.pop_back();
		}
		ll val = tree.query(stack.back().Y, i-1);
		val += B[i];
		mam.insert(val);
		stack.push_back(MP(H[i], i));
		tree.set(i, *std::prev(mam.end()));
	}

	std::cout << tree.query(n, n) << "\n";

	return 0;
}