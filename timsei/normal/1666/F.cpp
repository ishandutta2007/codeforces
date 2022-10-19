#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 5005;

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

namespace ModCalculator {
    const int MOD = 998244353;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline int Sub(int x, int y) {
        Dec(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
    inline int Ksm(int x, int y) {
        int ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret = Mul(ret, x);
            x = Mul(x, x);
        }
        return ret;
    }
    inline int Inv(int x) {
        return Ksm(x, MOD - 2);
    }
}
using namespace ModCalculator;

int n, _n, a[N], cnt[N];
int C[N][N], dp[2][N];

void prework() {
    n = 5000;
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
}

void solve() {
    read(n); _n = n / 2;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[tot]) {
            ++cnt[tot];
        } else {
            a[++tot] = a[i];
            cnt[tot] = 1;
        }
    }
    n = tot;

    if (cnt[1] > 1) {
        printf("0\n");
        return;
    }

    int pre = 0, cur = 1, sum = 1;
    for (int j = 0; j <= _n; ++j) {
        dp[pre][j] = 0;
    }
    dp[pre][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= _n; ++j) {
            dp[cur][j] = 0;
        }
        for (int j = 1; j <= i && j <= _n; ++j) {
            int x = j - 1 + (j == _n) -  (sum - j);
            if (x > 0) {
                dp[cur][j] = Mul(dp[pre][j], C[x][cnt[i]]);
            }
            x = j - 2 - (sum - j + 1);
            if (x >= 0) {
                Inc(dp[cur][j], Mul(dp[pre][j - 1], C[x][cnt[i] - 1]));
            }
        }
        sum += cnt[i];
        swap(pre, cur);
    }
    printf("%d\n", dp[pre][_n]);
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}