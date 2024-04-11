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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll f[maxn][2];
vector<array<ll, 2>> v;
map<ll, ll> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; v.clear(); mp.clear(); v.pb({-1, -1});
        for (i = 1; i <= n; i++) {
            f[i][0] = 0; f[i][1] = 0;
        }

        for (i = 1; i <= n; i++) {
            cin >> a[i]; v.pb({a[i], i});
        }

        sort(v.begin(), v.end());
        for (i = 1; i <= n; i++) {
            if (v[i][0] == v[i - 1][0]) a[v[i][1]] = a[v[i - 1][1]];
            else a[v[i][1]] = i;
        }

        /* for (i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << nl; */

        for (i = 1; i <= n; i++) {
            f[a[i]][i % 2]++;
        }

        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            if (abs(f[i][0] - f[i][1]) > 1) flag[0] = 0;
            if (f[i][0] > f[i][1] && (i % 2)) flag[0] = 0;
            if (f[i][0] < f[i][1] && (i % 2) == 0) flag[0] = 0;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}