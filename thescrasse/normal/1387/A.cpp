#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d, vl[maxn][2], u, g, visited[maxn], s, x;
long double r[maxn];
vector<array<ll, 3>> el, abv;
vector<array<ll, 2>> adj[maxn];
set<array<ll, 2>> sl;
array<ll, 2> y;

void pty(ll a, ll b, ll c, ll d) {
    // cout << "pty " << ' ' << a << ' ' << b << ' ' << c << ' ' << d << nl;
    if (a == -c && b == -d) return;
    if (a == -c && b != -d) {
        cout << "NO"; exit(0);
    }
    if (b == -d) y = {1, 0};
    y = {a + c, b + d};
    g = __gcd(abs(y[0]), abs(y[1]));
    y[0] /= g; y[1] /= g;
    if (y[0] < 0) {
        y[0] *= -1; y[1] *= -1;
    }
    // cout << y[0] << ' ' << y[1] << nl;
    sl.insert(y);
    if (sl.size() > 1) {
        cout << "NO"; exit(0);
    }
}

void dfs(ll s) {
    // cout << "dfs " << s << nl;
    for (auto o : adj[s]) {
        u = o[0]; x = o[1];
        // cout << u << ' ' << x << ' ' << visited[u] << nl;
        if (visited[u] == 1) {
            a = vl[s][0]; b = vl[s][1];
            c = vl[u][0]; d = vl[u][1] - x;
            pty(a, b, c, d);
            continue;
        }
        visited[u] = 1;
        vl[u][0] = -vl[s][0];
        vl[u][1] = x - vl[s][1];
        dfs(u);
    }
}

void fll(ll s, ll t) {
    if (visited[s] == 3) return;
    // cout << "fll " << ' ' << s << ' ' << t << nl;
    visited[s] = 3;
    if (t == 1) {
        r[s] = (long double)-vl[s][0] * y[1] / y[0];
        r[s] = (long double)r[s] + vl[s][1];
    } else {
        r[s] = (long double)m * vl[s][0] + vl[s][1];
    }
    for (auto u : adj[s]) fll(u[0], t);
}

void fz(ll s) {
    if (visited[s] == 2) return;
    visited[s] = 2;
    abv.pb({-vl[s][0] * vl[s][1], vl[s][0], vl[s][1]});
    for (auto u : adj[s]) fz(u[0]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        el.pb({a, b, c});
        adj[a].pb({b, c}); adj[b].pb({a, c});
    }

    for (i = 1; i <= n; i++) {
        if (visited[i] != 0) continue;
        visited[i] = 1;
        sl.clear();
        flag[0] = 0; flag[1] = 0;
        vl[i][0] = 1; vl[i][1] = 0;
        dfs(i);
        if (sl.size() == 1) {
            fll(i, 1);
        } else {
            abv.clear(); fz(i); s = abv.size(); res = INF; m = -1;
            sort(abv.begin(), abv.end());
            a = -s; b = 0;
            for (auto u : abv) b += u[0];
            /* for (auto u : abv) {
                cout << u[0] << ' ' << u[1] << ' ' << u[2] << nl;
            } */
            for (j = 0; j < s; j++) {
                k = a * abv[j][0] + b;
                // cout << j << ' ' << k << ' ' << a << ' ' << b << nl;
                if (k < res) {
                    res = k; m = abv[j][0];
                }
                a += 2; b -= (2 * abv[j][0]);
            }
            // cout << "m = " << m << nl;
            fll(i, 2);
        }
    }

    /* for (i = 1; i <= n; i++) cout << visited[i] << ' ';
    cout << nl; */

    cout << fixed << setprecision(1);
    cout << "YES" << nl;
    for (i = 1; i <= n; i++) {
        cout << r[i] << ' ';
    }

    return 0;
}