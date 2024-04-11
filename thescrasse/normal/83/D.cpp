// 83D
// Numbers

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 20700000

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, er[maxn + 10], x, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> a >> b >> k;

    flag[0] = 0;
    for (i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            cout << 0;
            return 0;
        }
    }

    res = 0;

    if (k >= 97) {
        for (i = 0; i <= maxn; i++) er[i] = 1;
        for (i = 2; i <= maxn; i++) {
            if (er[i] == 1) {
                for (j = 2 * i; j <= maxn; j += i) {
                    if (er[j] == 1) er[j] = i;
                }
            }
        }

        for (i = (a + k - 1) / k; i <= b / k; i++) {
            if (er[i] >= k || (er[i] == 1 && i >= k) || i == 1) res++;
        }
    } else {
        ll pr[24] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
        for (i = 0; i < 24; i++) {
            if (k == pr[i]) m = i;
        }
        for (i = 0; i < 1 << m; i++) {
            p = __builtin_popcountll(i);
            if (p >= 9) continue;
            x = k;
            for (j = 0; j < m; j++) {
                if ((i >> j) & 1 == 1) x *= pr[j];
            }
            if (p % 2 == 0) res += b / x - (a - 1) / x;
            else res -= b / x - (a - 1) / x;
        }
    }

    cout << res;

    return 0;
}