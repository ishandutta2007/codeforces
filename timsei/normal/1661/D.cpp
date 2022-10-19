#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, t, k;
long long A[N], S2[N], S[N], ans;

void rmain() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	for(int i = 1; i <= n + 1; ++ i) S2[i] = S[i]  = 0;
	ans = 0;
	for(int i = n; i >= k; -- i) {
		S2[i] = S2[i + 1] + S2[i];
		S[i] = S[i + 1] + S[i];
		A[i] -= S2[i] * i + S[i];
		if(A[i] <= 0) continue;
		else {
			long long cur = (A[i] - 1) / k + 1;
			ans += cur;
			S[i] -= cur * (i - k);
			S[i - k] += cur * (i - k);
			S2[i] += cur;
			S2[i - k] -= cur;
		}
	}
	long long res = 0;
	for(int i = k - 1; i >= 1; -- i) {
		S2[i] = S2[i + 1] + S2[i];
		S[i] = S[i + 1] + S[i];
		A[i] -= S2[i] * i + S[i];
		if(A[i] > 0) {
			res = max(res, (A[i] - 1) / i + 1);
		}
	}
	cout << ans + res << endl;
}

int main() {
	for(t = 1; t --;) {
		rmain();
	}
}