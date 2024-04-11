#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, x, y, A[N];

vector < int > Vec;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= m; ++ i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		if(l != 1) continue;
		Vec.push_back(r);
	}
	sort(Vec.begin(), Vec.end());
	int ans = 1e9;
	int it = 0;
	A[n + 1] = 1e9;
	for(int i = 1; i <= n + 1; ++ i) {
		while(it < (int) Vec.size() && Vec[it] < A[i]) ++ it;
		ans = min(ans, i - 1 + ((int)Vec.size() - it));
	}
	cout << ans << endl;
}