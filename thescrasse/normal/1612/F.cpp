#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 200010

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
int mx[maxn];
vector<array<int, 2>> v;
deque<array<int, 3>> q;

void clean() {
    int i;
    /* cout << "before clean" << nl;
    for (auto u : q) cout << u[0] _ u[1] _ u[2] << nf; */

    vector<array<int, 3>> nw;
    for (i = 0; i < maxn; i++) mx[i] = 0;
    for (auto [x, y, d] : q) mx[x] = max(mx[x], y);
    for (i = maxn - 2; i >= 0; i--) mx[i] = max(mx[i], mx[i + 1]);
    /* for (i = 0; i <= 10; i++) cout << mx[i] << ' ';
    cout << nl; */
    for (auto [x, y, d] : q) {
        if (y >= mx[x]) {
            nw.pb({x, y, d}); mx[x] = INF;
        }
    }
    q.clear();
    for (auto u : nw) q.pb(u);

    /* cout << "clean" << nf;
    for (auto u : q) cout << u[0] _ u[1] _ u[2] << nf; */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> t;
    for (i = 1; i <= t; i++) {
        cin >> a >> b; v.pb({a, b});
    }

    sort(v.begin(), v.end());

    q.pb({1, 1, 0}); flag[0] = 1;
    while (true) {
        auto [x, y, d] = q.front();
        if (flag[0] == 0 && d <= 50 && d == q.back()[2]) {
            clean(); flag[0] = 1; continue;
        }
        q.pop_front(); flag[0] = 0;

        // cout << x _ y _ d << nf;

        if (x == n && y == m) {
            cout << d << nl; return 0;
        }
        array<int, 2> o = {x, y};
        if (binary_search(v.begin(), v.end(), o)) k = 1;
        else k = 0;

        // cout << "new" _ min(n, x + y + k) _ y _ d + 1 << nl;
        // cout << "new" _ x _ min(m, x + y + k) _ d + 1 << nl;
        if (x != n) q.pb({min(n, x + y + k), y, d + 1});
        if (y != m) q.pb({x, min(m, x + y + k), d + 1});
    }

    cout << res << nl;

    return 0;
}