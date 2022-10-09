// 1061F
// Lost Root

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, d, p, s;
vector<ll> v, w;

ll ask(ll a, ll b, ll c) {
    string s;
    cout << "? " << a << ' ' << b << ' ' << c << nf;
    cin >> s; return (s == "Yes");
}

void clm(ll a) {
    cout << "! " << a << nf;
}

vector<ll> lv(ll a, ll b) {
    ll x; vector<ll> v;
    for (ll c = 1; c <= n; c++) {
        x = ask(a, c, b);
        if (x == 1) v.pb(c);
    }
    return v;
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> k; m = 1; d = 1; p = 1;
    while (m != n) {
        p *= k; m += p; d++;
    }

    for (i = 0; i < 43; i++) {
        a = uniform_int_distribution<ll>(1, n)(rng);
        b = uniform_int_distribution<ll>(1, n)(rng);
        v = lv(a, b); s = v.size();
        if (s == 2 * d - 1) {
            flag[0] = 1; break;
        }
    }

    if (flag[0] == 0) {
        while (true) {}
    }

    for (auto u : v) {
        if (u == a || u == b) continue;
        w = lv(a, u); s = w.size();
        if (s == d) {
            clm(u); return 0;
        }
    }

    return 0;
}