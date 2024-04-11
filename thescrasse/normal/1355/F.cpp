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
#define bn1 177
#define bn2 629
#define bn3 (ll)1e9
#define bn4 (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll er[maxn];
vector<ll> pr1, pr2, pr1c, pr2c, pr1m;
vector<array<ll, 2>> pr2m;

ll ask(ll x) {
    cout << "?" _ x << nf;
    cin >> x; return x;
}

void clm(ll x) {
    cout << "!" _ x << nf;
}

ll find_pw(ll x) {
    ll r = x;
    while (r <= bn3) r *= x;
    r /= x; return r;
}

ll padic(ll x, ll p) {
    ll r = 0;
    while (x % p == 0) {
        x /= p; r++;
    }
    return r;
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    for (i = 0; i < maxn; i++) er[i] = i;
    for (i = 2; i < maxn; i++) {
        if (er[i] != i) continue;
        for (j = 2 * i; j < maxn; j += i) er[j] = i;
    }

    for (i = 2; i <= bn2; i++) {
        if (er[i] == i) {
            if (i <= bn1) pr1.pb(i);
            else pr2.pb(i);
        }
    }

    pr1c = pr1; pr2c = pr2;

    while (!pr1.empty()) {
        a = pr1.back(); pr1.pop_back();
        if (pr1.empty()) {
            pr1m.pb(a); break;
        }
        b = pr1.back(); pr1.pop_back();

        if ((double)a * b <= 1e18) {
            pr1.pb(a * b);
        } else {
            pr1.pb(b); pr1m.pb(a);
        }
    }

    while (!pr2.empty()) {
        a = pr2.back(); pr2.pop_back();
        if (pr2.empty()) {
            pr2m.pb({a, b}); break;
        }
        b = pr2.back(); pr2.pop_back();

        if ((double)a * b <= bn4) {
            pr2.pb(a * b);
        } else {
            pr2.pb(b); pr2m.pb({a, b});
        }
    }

    cin >> t;
    while (t--) {
        res = 1; n = 1; flag[0] = 0;
        for (auto u : pr1m) {
            a = ask(u);
            if (a != 1) {
                for (auto e : pr1c) {
                    if (padic(a, e) >= 1) {
                        b = ask(find_pw(e)); n *= b;
                        res *= (padic(b, e) + 1);
                    }
                }
            }
        }

        if (res == 1) {
            clm(8); continue;
        }
        if (res == 2) {
            clm(9); continue;
        }

        for (auto [u, k] : pr2m) {
            if (n * k * k * k > bn3) continue;
            a = ask(u);
            if (a != 1) {
                clm(4 * res); flag[0] = 1; break;
            }
        }

        if (flag[0] == 0) clm(2 * res);
    }

    return 0;
}