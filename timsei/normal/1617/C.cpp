#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, S[N], A[N];
bool vis[N];

void rmain() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) S[i] = vis[i] = 0;
	int ans = n;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
		if(A[i] <= n) {
			if(!vis[A[i]]) {
				vis[A[i]] = 1;
				++ S[A[i]];
				-- ans;
				continue;
			}
		}
		int it = A[i] / 2;
		if(A[i] % 2 == 0) -- it;
		it = min(it, n);
		if(it) ++ S[it];
	}
	S[n + 1] = 0;
	for(int i = n; i >= 1; -- i) {
		S[i] += S[i + 1];
		if(S[i] < n - i + 1) {
			puts("-1");
			return;
		}
	}
	cout << ans << endl;
}

int main() {
	int t; for(cin >> t; t --;) rmain();
}