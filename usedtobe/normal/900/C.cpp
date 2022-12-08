#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
int a[N], c[N], ans, b[N], tt[N];
int n;
void add(int x, int y) {
	for (int i = x; i <= n; i += i & (-i)) c[i] += y;
}
int ask(int x) {
	int an = 0;
	for (int i = x; i; i -= i & (-i)) an += c[i];
	return an;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		int t = ask(a[i]);
		if (t == i - 2) b[a[i]] = 1;
		else if (t == i - 1) tt[a[i]] = 1;
		add(a[i], 1);
	}
	memset(c, 0, sizeof c);
	int mx = -10;
	for (int i = n; i >= 1; --i) {
		int tmp = ask(a[i]);
		if (tt[a[i]]) tmp--;
		if (mx < tmp || (mx == tmp && ans > a[i])) {
			mx = tmp;
			ans = a[i];
		}
		add(a[i], b[a[i]]);
	}
	printf("%d\n", ans);
	return 0;
}