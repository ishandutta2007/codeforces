#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll np, kp, x;
vector<ll> v;

void filll(ll ty, ll l, ll r) {
    ll i;
    if (ty == 1) v.clear();
    for (i = l; i <= r; i++) v.pb(i);
}

void revert() {
    ll i;
    bool vis[n + 10];
    for (i = 1; i <= n; i++) vis[i] = false;
    for (auto u : v) vis[u] = true;
    v.clear();
    for (i = 1; i <= n; i++) {
        if (vis[i] == false) v.pb(i);
    }
}

ll ask() {
    ll x;
    if (flag[0] == 1) revert();
    cout << "? ";
    for (auto u : v) cout << u << ' ';
    cout << nf;
    cin >> x; return x;
}

void clm(ll x) {
    cout << "! " << x << nf; exit(0);
}

ll solve11_3(ll n) {
    ll i, d, rm, r = 0;
    d = (3 * k - n) / 2;
    rm = (n - d) / 3;
    // cout << "n, k = " << n _ k << nl;
    // cout << "d, rm = " << d _ rm << nl;
    for (i = d; i <= n - rm; i += rm) {
        filll(1, 1, d); filll(0, i + 1, i + rm);
        r ^= ask();
    }
    return r;
}

ll solve00(ll n, ll k) {
    ll i, l, x = 0;
    for (i = 1; i <= n; i++) {
        if (i <= 3 * k && ((i % k) == (n % k))) l = i;
    }
    x ^= solve11_3(l);
    for (i = l; i <= n - k; i += k) {
        filll(1, i + 1, i + k); x ^= ask();
    }
    return x;
}

ll solve11(ll n, ll k) {
    ll i, l, x = 0;
    for (i = 1; i <= n; i++) {
        if (i <= 3 * k && ((i % k) == (n % k)) && (((n - i) % (2 * k)) == 0)) l = i;
    }
    x ^= solve11_3(l);
    for (i = l; i <= n - k; i += k) {
        filll(1, i + 1, i + k); x ^= ask();
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> k;
    np = n % 2; kp = k % 2;

    if (np == 1 && kp == 0) {
        cout << -1 << nl; return 0;
    }

    if (n == k) {
        filll(1, 1, n); x ^= ask();
        clm(x);
    }

    if (n == 2 * k) {
        filll(1, 1, n / 2); x ^= ask();
        filll(1, n / 2 + 1, n); x ^= ask();
        clm(x);
    }

    if (np == 1 && kp == 1) {
        x ^= solve11(n, k); clm(x);
    } else if (np == 0 && kp == 1) {
        if (k >= n / 2) {
            k = n - k; flag[0] = 1; // ricordati revert
        }
        filll(1, n - k + 1, n); x ^= ask();
        x ^= solve11(n - k, k); clm(x);
    } else {
        x ^= solve00(n, k); clm(x);
    }

    return 0;
}