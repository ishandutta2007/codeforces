#include <bits/stdc++.h>
using namespace std;
vector<int> a[300020];
int s[300020], n, A, B, x, y;
int dfs(int x, int y) {
	s[x] = 1;
	for (int i: a[x]) {
		if (i != y) {
			s[x] += dfs(i, x);
		}
	}
	return s[x];
}
int main() {
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(A, 0);
	int sb = s[B];
	dfs(B, 0);
	int sa = s[A];
	printf("%lld\n", n * (n - 1LL) - (long long)sa * sb);
	return 0;
}