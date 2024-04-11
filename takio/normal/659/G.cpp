#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
//#define piii pair <int, pii>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;

const int N = 1000100, mod = 1e9 + 7;

LL dp[N];
int a[N];

LL pm (LL x, LL y) {
    LL r = 1;
    while (y) {
        if (y & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &a[i]);
            a[i]--;
        }
        dp[1] = a[1];
        int p = 1, res = a[1];
        LL sum = 0, sum2 = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] <= a[i]) {
                dp[i] = (dp[i - 1] * a[i - 1] + a[i]) % mod;
                sum = 0;
                sum2 = 1;
                p = i;
            } else {
                sum++;
                (sum *= a[i]) %= mod;
                (sum2 *= a[i]) %= mod;
                (dp[i] = sum * a[i] + a[i]) %= mod;
//                cout << sum << ' ' << sum2 <<' ' << a[i] <<' ' << dp[i] << endl;
                if (p != 1) {
                    if (a[p - 1] >= a[p + 1]) (dp[i] += sum2 * a[i] % mod * dp[p - 1] % mod) %= mod;
                    else {
                        (dp[i] += sum2 * a[i] % mod * dp[p - 1] % mod * pm (a[p + 1], mod - 2) % mod * a[p - 1] % mod) %= mod;
                    }
                }
            }
//            cout << i << ' ' << dp[i] << endl;
            (res += dp[i]) %= mod;
        }
        cout << res << endl;
    }
}