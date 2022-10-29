#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans;
int n, a[100010];
unordered_map<int, int> T;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 30; ++j) {
			int t = 1 << j; 
			if (t > a[i] && T.count(t - a[i])) 
				ans += T[t - a[i]];
		}
		++T[a[i]];
	}
	printf("%I64d\n", ans);
}