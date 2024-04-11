#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], p[maxn][2], c[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < maxn; i++) c[i] = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        p[a[i]][0] = i;
    }
    for (i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        p[b[i]][1] = i;
    }

    /* for (i = 0; i < n; i++) {
        cout << p[i][0] << ' ' << p[i][1] << endl;
    } */

    for (i = 0; i < n; i++) {
        k = p[i][0] - p[i][1] + n; k %= n;
        c[k]++;
    }

    res = 0;
    for (i = 0; i < n; i++) {
        res = max(res, c[i]);
    }

    cout << res;

    return 0;
}