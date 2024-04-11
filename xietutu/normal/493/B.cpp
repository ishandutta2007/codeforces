#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
const int maxn = 200005;
ll s1,s2;
int n,m,t,last,a[maxn],b[maxn];
int main() {
	scanf("%d",&t);
	for (int i = 1; i <= t; ++i) {
		int v;
		scanf("%d",&v);
		if (v > 0) s1 = s1 + v, a[++n] = v;
		else s2 = s2 - v, b[++m] = -v;
		if (i == t) {
			if (v > 0) last = 1;
			else last = 2;
		}
	}
	if (s1 > s2) printf("first\n");
	else if (s2 > s1) printf("second\n");
	else {
		int t = 0;
		for (int i = 1; i <= n && i <= m; ++i)
			if (a[i] > b[i]) {
				t = 1; break;
			}
			else if (a[i] < b[i]) {
				t = 2; break;
			}
		if (t) {
			if (t == 1) printf("first\n");
			else printf("second\n");
		}
		else if (n > m) printf("first\n");
		else if (n < m) printf("second\n");
		else if (last == 1) printf("first\n");
		else printf("second\n");
	}
}