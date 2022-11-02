#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 100005, mod = 1e9 + 7, M = 100;
int a[N], dp[M + 10];

struct mat {
    int a[105][105];
    inline void init () {
        memset (a, 0, sizeof a);
    }
};

inline mat mul (mat a, mat b, int n) {
    mat c;
    c.init ();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                (c.a[i][j] += 1LL * a.a[i][k] * b.a[k][j] % mod) %= mod;
            }
        }
    }
    return c;
}

inline mat pow (mat a, int k, int n) {
    mat res;
    res.init ();
    for (int i = 1; i <= n; i++) {
        res.a[i][i] = 1;
    }
    while (k) {
        if (k & 1) res = mul(res, a, n);
        a = mul (a, a, n);
        k >>= 1;
    }
    return res;
}

inline int read() {
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    dp[0] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= n; j++) if (i - a[j] >= 0) {
            (dp[i] += dp[i - a[j]]) %= mod;
        }
    }
//    cout << "xxx\n";
    if (m < M) {
        int res = 0;
        for (int i = 0; i <= m; i++) {
            (res += dp[i]) %= mod;
        }
        cout << res << endl;
        return 0;
    }
    mat A;
    A.init ();
    for (int i = 0; i < M; i++) {
        A.a[1][i + 1] = dp[i];
        if (i != M - 1) (A.a[1][M + 1] += dp[i]) %= mod;
    }
    mat b;
    b.init ();
    for (int i = 1; i < M; i++) {
        b.a[i + 1][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        b.a[M - a[i] + 1][M]++;
    }
    b.a[M + 1][M + 1] = b.a[M][M + 1] = 1;
//    A.w ();
//    b.w ();
    A = mul (A, pow (b, m - M + 2, M + 1), M + 1);
    cout << A.a[1][M + 1] << endl;
}