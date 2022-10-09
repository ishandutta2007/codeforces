#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll mt[maxn][maxn], p[maxn];

ll ps(ll l, ll r) {
    return p[r] - p[l - 1];
}

ll psd(ll l, ll r) {
    return mt[r][l] - mt[l - 1][r + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> b[i]; p[i] = p[i - 1] + a[i] * b[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            mt[i][j] = a[i] * b[j];
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            mt[i][j] += mt[i - 1][j + 1];
        }
    }

    res = -INF;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            res = max(res, ps(1, n) - ps(i, j) + psd(i, j));
            // cout << i _ j _ ps(i, j) _ psd(i, j) << nl;
        }
    }

    cout << res << nl;

    return 0;
}