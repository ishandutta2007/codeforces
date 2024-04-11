#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 1;

int tmp[3], n, x, mx, A[N];

int get(int x) {
	for(int i = 1; i <= n; ++ i) if(A[i] == x) return 1;
	return 0;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		memset(tmp, 0, sizeof(tmp));
		mx = 0;
		tmp[1] = INF; tmp[2] = INF;
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &A[i]);
			mx = max(mx, A[i]);
			tmp[A[i] % 3] = min(tmp[A[i] % 3], A[i]);
		}
		int ans = mx / 3;
		if(tmp[1] != INF) ++ ans;
		if(tmp[2] != INF) ++ ans;
		if(tmp[1] != INF && tmp[2] != INF) {
			if(mx % 3 == 0) -- ans;
			else if(tmp[1] >= 4 && mx % 3 == 1 && !get(mx - 1)) -- ans; 
		}
		printf("%d\n", ans);
	}
}