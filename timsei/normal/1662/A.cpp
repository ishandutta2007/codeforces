#include<bits/stdc++.h>
using namespace std;
int T, n, mx[15];
int main() {
	for(scanf("%d", &T); T --; ) {
		for(int i = 1; i <= 10; ++ i)
			mx[i] = 0;
		scanf("%d", &n);
		for(int i = 1, u, v; i <= n; ++ i)
			scanf("%d%d", &u, &v), mx[v] = max(mx[v], u);
		int ans = 0;
		for(int i = 1; i <= 10; ++ i)
			if(!mx[i]) {
				ans = -1;
				break;
			}
			else
				ans += mx[i];
		if(ans < 0)
			puts("MOREPROBLEMS");
		else
			printf("%d\n", ans);
	}
}