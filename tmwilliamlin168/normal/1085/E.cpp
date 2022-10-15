#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, m, ans[256]; bool found, used[256];
char s[MAXN], a[MAXN], b[MAXN];
void output() {
	puts("YES");
	int pos = 1;
	for (int i = 1; i <= m; i++)
		if (!used[i]) {
			while (ans[pos]) pos++;
			ans[pos] = i;
		}
	for (int i = 1; i <= m; i++)
		putchar('a' + ans[i] - 1);
	putchar('\n');
}
void work(int pos, bool ea, bool eb) {
	if (found) return;
	if (pos == n + 1) {
		found = true;
		output();
		return;
	}
	if (ans[s[pos]]) {
		if (ea && ans[s[pos]] < a[pos]) return;
		if (eb && ans[s[pos]] > b[pos]) return;
		work(pos + 1, ea && ans[s[pos]] == a[pos], eb && ans[s[pos]] == b[pos]);
	} else {
		for (int i = 1; i <= m; i++) {
			if (used[i]) continue;
			if (ea && i <= a[pos]) continue;
			if (eb && i >= b[pos]) continue;
			used[i] = true, ans[s[pos]] = i;
			found = true, output();
			return;
		}
		if (ea && !used[a[pos]] && (!eb || a[pos] <= b[pos])) {
			used[a[pos]] = true, ans[s[pos]] = a[pos];
			work(pos + 1, ea && ans[s[pos]] == a[pos], eb && ans[s[pos]] == b[pos]);
			used[a[pos]] = false, ans[s[pos]] = 0;
		}
		if (eb && !used[b[pos]] && (!ea || a[pos] <= b[pos])) {
			used[b[pos]] = true, ans[s[pos]] = b[pos];
			work(pos + 1, ea && ans[s[pos]] == a[pos], eb && ans[s[pos]] == b[pos]);
			used[b[pos]] = false, ans[s[pos]] = 0;
		}
	}
}
int main() {
	int T; read(T);
	while (T--) {
		read(m);
		scanf("\n%s", s + 1);
		scanf("\n%s", a + 1);
		scanf("\n%s", b + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= m; i++) {
			used[i] = false;
			ans[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			s[i] -= 'a' - 1;
			a[i] -= 'a' - 1;
			b[i] -= 'a' - 1;
		}
		found = false;
		work(1, 1, 1);
		if (!found) puts("NO");
	}
	return 0;
}