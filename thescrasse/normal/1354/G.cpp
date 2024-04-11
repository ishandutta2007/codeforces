// 1354G
// Find a Gift

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, qr, x;
vector<ll> va, vb;

ll ask(vector<ll> a, vector<ll> b) {
    string s;
    cout << "? " << a.size() << ' ' << b.size() << nl; qr++;
    for (auto u : a) cout << u << ' ';
    cout << nl;
    for (auto u : b) cout << u << ' ';
    cout << nf;
    cin >> s;
    if (s == "FIRST") return 1;
    else if (s == "SECOND") return 2;
    else if (s == "EQUAL") return 3;
    else if (s == "WASTED") exit(0);
    else return -1;
}

void clm(ll x) {
    cout << "! " << x << nf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> t;
    while (t--) {
        cin >> n >> k; qr = 0; m = 0;
        for (i = 2; i <= n; i <<= 1) {
            va.clear(); vb.clear();
            for (j = 1; j <= i / 2; j++) {
                va.pb(j); vb.pb(j + i / 2);
            }
            if (ask(va, vb) != 3) {
                m = i; break;
            }
        }
        if (m == 0) m = i;

        x = 0;
        for (i = m / 2; i >= 1; i >>= 1) {
            if (x + i + m / 2 > n) continue;
            va.clear(); vb.clear();
            for (j = 1; j <= x + i; j++) {
                va.pb(j); vb.pb(j + m / 2);
            }
            if (ask(va, vb) == 3) x += i;
        }

        flag[0] = 0;
        while (qr != 50) {
            a = uniform_int_distribution<ll>(2, n)(rng);
            if (ask({1}, {a}) == 2) {
                flag[0] = 1; break;
            }
        }

        if (flag[0] == 1) clm(1);
        else clm(m / 2 + x + 1);
    }

    return 0;
}