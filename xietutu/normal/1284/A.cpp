#include <bits/stdc++.h>
using namespace std;

int n, m;
char sa[22][22], sb[22][22];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) scanf("%s", sa[i]);
	for (int i = 0; i < m; ++ i) scanf("%s", sb[i]); 
	int Q; scanf("%d", &Q);
	while (Q --) {
		int x; scanf("%d", &x);
		printf("%s%s\n", sa[(x - 1) % n], sb[(x - 1) % m]);
	}
	return 0;
}