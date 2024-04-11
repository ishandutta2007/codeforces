#include<bits/stdc++.h>
using namespace std;
int T, n, m;

int main() {
	for(scanf("%d", &T); T --; ) {
		scanf("%d%d", &n, &m);
		int mxr = 0, mxw = 0;
		for(int i = 1, u, v; i <= m; ++ i)
			scanf("%d%d", &u, &v), mxr = max(mxr, u), mxw = max(mxw, v);
		if(mxr + mxw > n) {
			puts("IMPOSSIBLE");
			continue;
		}
		for(int i = 1; i <= mxr; ++ i)
			putchar('R');
		for(int i = 1; i <= mxw; ++ i)
			putchar('W');
		for(int i = 1; i <= n - mxr - mxw; ++ i)
			putchar('R');
		puts("");
	}
}