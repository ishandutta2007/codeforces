#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int INF = 1000000666;
struct Tree{
	int BOTTOM;
	VI t;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz){
			BOTTOM *= 2;
		}
		
		t.resize(BOTTOM*2, INF);
	}

	void set(int a, int v){
		a += BOTTOM;
		t[a] = v;
		while(a > 1){
			a >>= 1;
			t[a] = std::min(t[a<<1], t[(a<<1)+1]);
		}
	}

	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int ret = INF;
		while(a < b){
			if(a&1) ret = std::min(ret, t[a++]);
			if(b&1) ret = std::min(ret, t[--b]);
			a>>=1;b>>=1;
		}
		return ret;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	Tree tree;
	tree.build(n+1);

	int sum = 0;

	std::vector<PII> stack;
	stack.push_back(MP(INF, 0));

	int ans = 0;

	tree.set(0, 0);
	REP(i, 1, n+1){
		
		int a = A[i-1];

		sum += a;
		tree.set(i, sum);

		while(SZ(stack) && stack.back().X <= a) stack.pop_back();
		stack.push_back(MP(a, i));

		REP(j, 1, SZ(stack)){
			int min = stack[j].X;
			

			ans = std::max(ans, sum-tree.query(stack[j-1].Y, stack[j].Y-1)-min);
		}

	}

	std::cout << ans << "\n";

	return 0;
}