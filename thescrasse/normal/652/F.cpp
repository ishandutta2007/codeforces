#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define gig (ll)1e12
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll l, w[maxn], x[maxn], tt, d, f[maxn];
char ch;
array<ll, 2> c[maxn];
vector<array<ll, 3>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> l >> t;
    for (i = 1; i <= n; i++) {
        cin >> m >> ch;
        if (ch == 'R') v.pb({m, 1, i});
        else v.pb({m, 2, i});
        if (ch == 'R') k++;
        else k--;
    }

    sort(v.begin(), v.end());
    for (i = 1; i <= n; i++) {
        b[i] = v[i - 1][0] - 1; x[i] = v[i - 1][1]; f[v[i - 1][2]] = i;
    }

    for (i = 1; i <= n; i++) {
        a[i] = b[(i + (k * (t / l)) - 1 + ((2 * INF) / n) * n) % n + 1];
        w[i] = x[(i + (k * (t / l)) - 1 + ((2 * INF) / n) * n) % n + 1];
    }
    t %= l;

    /* for (i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << nl; */

    k = 0;
    for (i = 1; i <= n; i++) {
        if (w[1] == w[i]) continue;
        if (w[1] == 1 && (a[i] - a[1] + l) % l < 2 * t) k++;
        if (w[1] == 1 && (a[i] - a[1] + l) % l + l < 2 * t) k++;
        if (w[1] == 2 && (a[1] - a[i] + l) % l <= 2 * t) k--;
        if (w[1] == 2 && (a[1] - a[i] + l) % l + l <= 2 * t) k--;
    }
    // cout << k << nl;

    for (i = 1; i <= n; i++) {
        if (w[i] == 1) c[i] = {(a[i] + t) % l, i};
        else c[i] = {(a[i] - t + l) % l, i};
    }
    sort(c + 1, c + n + 1);

    /* for (i = 1; i <= n; i++) cout << c[i][0] << ' ';
    cout << nl;
    for (i = 1; i <= n; i++) cout << c[i][1] << ' ';
    cout << nl; */

    for (i = 1; i <= n; i++) {
        if (c[i][1] == 1) d = (k - i + 1 + n) % n;
    }

    for (i = 1; i <= n; i++) {
        b[(i + d - 1 + ((2 * INF) / n) * n) % n + 1] = c[i][0];
    }

    for (i = 1; i <= n; i++) cout << b[f[i]] + 1 << ' ';
    cout << nl;

    return 0;
}