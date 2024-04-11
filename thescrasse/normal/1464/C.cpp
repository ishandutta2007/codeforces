#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[maxn], dp[maxn][2];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> t >> s; s = '#' + s;
    for (i = 1; i <= n; i++) {
        a[i] = (ll)s[i] - 'a';
    }
    for (i = 1; i <= n - 2; i++) {
        f[a[i] + 1]++;
    }

    t -= (1 << a[n]); t += (1 << a[n - 1]);
    for (i = 1; i <= n - 2; i++) {
        t += (1 << a[i]);
    }

    for (i = 1; i <= n; i++) {
        m = (1 << a[i]);
        // cout << i _ m << nl;
    }

    /* cout << t << nl;
    for (i = 1; i <= 30; i++) cout << i _ f[i] << nl; */

    for (i = 1; i <= 64; i++) {
        if ((t >> i) & 1) {
            if (f[i] == 0) {
                cout << "No" << nl; return 0;
            }
            f[i]--;
        }

        f[i + 1] += f[i] / 2;
    }

    cout << "Yes" << nl;

    return 0;
}