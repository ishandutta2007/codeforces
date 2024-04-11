#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 35;

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

char s[N], t[N];
int n, m, cnt[N], use[N];

void solve() {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    mset(cnt, 0);
    mset(use, 0);
    for (int i = 1; i <= m; ++i) {
        ++cnt[t[i] - 'A'];
    }
    for (int i = n; i >= 1; --i) {
        if (cnt[s[i] - 'A']) {
            use[i] = 1;
            --cnt[s[i] - 'A'];
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
            puts("NO");
            return;
        }
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        if (use[i]) {
            if (s[i] != t[j]) {
                puts("NO");
                return;
            }
            ++j;
        }
    }
    puts("YES");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}