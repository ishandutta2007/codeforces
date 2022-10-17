#include <bits/stdc++.h>
using namespace std;
int n, k, m, x;
vector<int> a[100020];
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x % m].push_back(x);
	}
	for (int i = 0; i < m; i++) {
		if (a[i].size() >= k) {
			printf("Yes\n");
			for (int j = 0; j < k; j++) {
				printf("%d%c", a[i][j], j == k - 1 ? '\n' : ' ');
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}