#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn], d[maxn], s;
vector<array<ll, 2>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            v.pb({max((ll)0, c[j] - a[i] + 1), max((ll)0, d[j] - b[i] + 1)});
        }
    }

    sort(v.begin(), v.end()); s = v.size();
    for (i = s - 2; i >= 0; i--) {
        v[i][1] = max(v[i][1], v[i + 1][1]);
    }

    // for (auto u : v) cout << u[0] << ' ' << u[1] << nl;

    res = INF;
    for (i = 0; i < s; i++) {
        res = min(res, v[i][0] + v[i + 1][1]);
    }
    res = min({res, v[0][1], v[s - 1][0]});

    cout << res;

    return 0;
}