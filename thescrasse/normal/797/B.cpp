#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll sfm(ll x) {
    return ((x % 2) + 2) % 2;
}

ll i, i1, j, k, k1, t, n, m[2], res, flag[10], a[maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    res = 0; flag[0] = 0; m[0] = INF; m[1] = -INF;
    for (i = 0; i < n; i++) {
        if (sfm(a[i]) == 0 && a[i] > 0) res += a[i];
        if (sfm(a[i]) == 1) {
            if (a[i] > 0) {
                flag[0]++; m[0] = min(m[0], a[i]);
            } else {
                m[1] = max(m[1], a[i]);
            }
        }
    }

    if (flag[0] > 0) {
        if (flag[0] % 2 == 0) res -= min(m[0], -m[1]);
        for (i = 0; i < n; i++) {
            if (sfm(a[i]) == 1 && a[i] > 0) {
                res += a[i];
            }
        }
    } else {
        res += m[1];
    }

    cout << res;

    return 0;
}