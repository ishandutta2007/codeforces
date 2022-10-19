#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, m;
int ans[MAXN], tot;

void Calc(int a, int b) {
    int c = __gcd(a, b);
    for (int i = 1; i * i <= c; ++i) {
        if (c % i) continue;
        ans[++tot] = i;
        ans[++tot] = c / i;
    }
}

void solve() {
    read(n); read(m);
    ans[tot = 1] = 1;
    ans[tot = 2] = 2;
    Calc(n - 1, m - 1);
    Calc(n, m - 2);
    Calc(n - 2, m);
    sort(ans + 1, ans + tot + 1);
    tot = unique(ans + 1, ans + tot + 1) - (ans + 1);
    printf("%d", tot);
    for (int i = 1; i <= tot; ++i) {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
}