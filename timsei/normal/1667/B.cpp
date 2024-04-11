#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e6 + 5;
const int Segment_Size = N * 4;
const int Bas = 5e5;

int n, m, x, y, A[N], tot, dp[N];

map <int, int> Map, C, D;

#define lb(x) (x & (-x))

struct BIT {
	int S[N];
	void add(int x, int v) {
		++ x;
		for(int i = x; i <= tot + 3; i += lb(i))
		S[i] = max(S[i], v);
	}
	int Sum(int x) {
		++ x;
		int res = -1e18;
		for(int i = x; i; i -= lb(i))
		res = max(res, S[i]);
		return res;
	}
	void init() {
		for(int i = 0; i <= tot + 3; ++ i)
		S[i] = -1e18;
	}
}B1, B2;

void rmain() {
	Map.clear(); C.clear(); D.clear(); 
	C[0] = 1;
	scanf("%lld", &n); tot = 0;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), A[i] += A[i - 1], C[A[i]] = 1;
	for(auto V : C) {
		D[V.first] = ++ tot;
	}
	B1.init(); B2.init();
	
	for(int i = 1; i <= n; ++ i) A[i] = D[A[i]];
	B1.add(D[0], 0 - 0);
	B2.add(tot + 1 - D[0], 0 + 0);
	Map[D[0]] = 0;
//	cerr << D[0] <<' ' << 0 - 0 <<"FUCK" << ' ' << B1.Sum(3) << ' ' << tot <<  endl;
	for(int i = 1; i <= n; ++ i) {
		dp[i] = max(B1.Sum(A[i] - 1) + i, B2.Sum(tot - A[i] + 1 - 1) - i);
		if(Map.count(A[i])) {
			dp[i] = max(dp[i], Map[A[i]]);
		}
//		cerr << i <<' ' << dp[i] << ' ' << A[i] << ' ' << tot - A[i] + 1 << ' ' << D[0] <<  endl;
//		cerr << B1.Sum(A[i] - 1) <<' ' << B2.Sum(tot - A[i]) << endl;
		Map[A[i]] = dp[i];
		B1.add(A[i], dp[i] - i);
		B2.add(tot - A[i] + 1, dp[i] + i);
	}
	cout << dp[n] << endl;
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}