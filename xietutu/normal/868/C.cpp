#include <bits/stdc++.h>
using namespace std;
int n, m, maxs, a[16];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
 		int s = 0;
		for (int j = 0; j < m; ++j) {
			int t;
			scanf("%d", &t);
			s ^= t * (1 << j);
		}
		++a[s];
	}	
	maxs = 1 << m;
	for (int i = 0; i < maxs; ++i)
		for (int j = 0; j < maxs; ++j)
			if ((i & j) == 0 && a[i] && a[j]) {
				puts("YES"); return 0;
			}
	puts("NO");
}