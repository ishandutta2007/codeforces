#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, ty, qr;
map<array<ll, 6>, ll> mp;
vector<array<ll, 2>> dv;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ask(ll h, ll w, ll i1, ll j1, ll i2, ll j2) {
    // cout << "ask " << h _ w _ i1 _ j1 _ i2 _ j2 << nf;
    if (ty == 1) {
        swap(h, w); swap(i1, j1); swap(i2, j2);
    }
    if (h == 0 || w == 0) return 1;
    if (mp[{h, w, i1, j1, i2, j2}] != 0) {
        return mp[{h, w, i1, j1, i2, j2}] - 1;
    }
    qr++;
    if (qr == 3 * floor(log2(n + m)) + 1) {
        while (true) {}
    }
    cout << "? " << h _ w _ i1 _ j1 _ i2 _ j2 << nf;
    ll x; cin >> x;
    mp[{h, w, i1, j1, i2, j2}] = x + 1;
    return x;
}

bool check(ll p, ll ty) {
    // cout << "check " << p _ ty << nl;
    ll x, y, z, k;

    // for (auto u : dv) cout << u[0] _ u[1] << nf;

    for (auto u : dv) {
        if (u[1] == -1) continue;
        if (u[1] == 0 && u[0] % p == 0) return false;
        if (u[1] == 1 && p % u[0] == 0) return true;
    }

    if (p == n) return true;

    k = p * ((n / p - 1) / 2);
    ll kk = uniform_int_distribution<ll>(0, 1)(rng);
    if (kk == 0) {
        y = ask(k, m, 1, 1, k + p + 1, 1);
        if (y == 0) return false;
        x = ask(k, m, 1, 1, k + 1, 1);
        if (x == 0) return false;
    } else {
        x = ask(k, m, 1, 1, k + 1, 1);
        if (x == 0) return false;
        y = ask(k, m, 1, 1, k + p + 1, 1);
        if (y == 0) return false;
    }

    if ((n / p) % 2 == 0) {
        z = ask(n / 2, m, 1, 1, n / 2 + 1, 1);
    } else {
        z = 1;
    }
    if (z == 0) return false;
    return true;
}

void solve() {
    dv.clear();
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            dv.pb({i, -1});
        }
    }

    shuffle(dv.begin(), dv.end(), rng);
    /* for (auto u : dv) cout << u[0] << ' ';
    cout << nl; */
    for (auto &u : dv) {
        if (check(u[0], ty) == true) u[1] = 1;
        else u[1] = 0;
    }

    a = 0;
    for (auto u : dv) {
        if (u[1] == 1) a++;
    }
    res *= a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> m; res = 1; qr = 0;
    solve(); swap(n, m); ty++; solve();

    cout << "! " << res << nl;

    return 0;
}