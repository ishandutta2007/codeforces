#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int n, k, A[N];

struct Node {
	int mx, sum;
};

vector < Node > L, R;

void rmain() {
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	L.clear(); R.clear();
	
	A[0] = 1e18; A[n + 1] = 1e18;

	Node H;
	H.mx = 0; H.sum = 0;
	
	for(int i = k + 1; i <= n + 1; ++ i) {
		H.sum += A[i];
		H.mx = max(H.mx, -H.sum);
		if(H.sum > 0) {
			R.push_back(H);
			H.mx = H.sum = 0;
		}
	}
	
	for(int i = k - 1; i >= 0; -- i) {
		H.sum += A[i];
		H.mx = max(H.mx, -H.sum);
		if(H.sum > 0) {
			L.push_back(H);
			H.mx = H.sum = 0;
		}
	}
	
	reverse(L.begin(), L.end());
	reverse(R.begin(), R.end());
	
	int cur = A[k];
	while(1) {
		if(!L.size() || !R.size()) {
			puts("YES");
			break;
		}
		if(cur < L.back().mx && cur < R.back().mx) {
			puts("NO"); break;
		}
		if(cur >= L.back().mx) {
			cur += L.back().sum;
			L.pop_back();
		}
		if(cur >= R.back().mx) {
			cur += R.back().sum;
			R.pop_back();
		}
	}
}

main() {
	int T;
	for(cin >> T; T --;) {
		rmain();
	}
}