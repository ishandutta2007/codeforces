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

struct Tree{
	std::vector<int> t;
	int BOTTOM;
	void build(VI A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		FOR(i, SZ(A)) t[i+BOTTOM] = A[i];
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)+1]);
	}
	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int mx = 0;
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
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		Tree tree;
		tree.build(A);
		int m;
		std::cin >> m;
		std::vector<PII> B(m);
		FOR(i, m) std::cin >> B[i].X >> B[i].Y;
		std::sort(B.begin(), B.end());
		std::vector<PII> C;
		C.push_back(B[0]);
		REP(i, 1, m){
			while(SZ(C) && C.back().Y < B[i].Y) C.pop_back();
			C.push_back(B[i]);
		}
		int ans = 0;
		int pos = 0;
		while(pos < n){
			//std::cerr << pos << std::endl;
			int left = pos;
			int right = n;
			while(left < right){
				int mid = (left+right)/2;
				int mx = tree.query(pos, mid);
				auto it = std::lower_bound(C.begin(), C.end(), MP(mx, 0));
				if(it != C.end() && it->Y >= mid-pos+1) left = mid+1;
				else right = mid;
			}
			if(left == pos){
				ans = -1;
				break;
			}
			ans++;
			pos = left;
		}
		std::cout << ans << "\n";
	}
	return 0;
}