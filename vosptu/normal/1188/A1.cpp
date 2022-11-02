#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
int deg[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}