#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

int mn[1 << 17];
int a[N][5], w[N], b[N * 5], col[N * 5];
int n, m, len, ans = 2000000001;

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			read(a[i][j]);
			b[++len] = a[i][j];
		}
		read(w[i]);
	}
	sort(b + 1, b + len + 1);
	len = unique(b + 1, b + len + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = lower_bound(b + 1, b + len + 1, a[i][j]) - b;
		}
	}	
	for (int _ = 1; _ <= 31; _++) {
		memset(mn, 0x3f, sizeof(mn));
		for (int i = 1; i <= len; i++) col[i] = rng() % 17;
		for (int i = 1; i <= n; i++) {
			int now = 0;
			for (int j = 0; j < m; j++) now |= (1 << col[a[i][j]]);
			mn[now] = min(mn[now], w[i]);
		}
		for (int mid = 1; mid < (1 << 17); mid <<= 1) {
			for (int i = 0; i < (1 << 17); i += (mid << 1)) {
				for (int j = 0; j < mid; j++) {
					mn[i + j + mid] = min(mn[i + j + mid], mn[i + j]);
				}
			}
		}
		for (int i = 0; i < (1 << 17); i++) {
			if (mn[i] != 0x3f3f3f3f && mn[(1 << 17) - 1 - i] != 0x3f3f3f3f) {
				ans = min(ans, mn[i] + mn[(1 << 17) - 1 - i]);
			}
		}
	}
	if (ans == 2000000001) ans = -1;
	print(ans, '\n');
    return 0;
}