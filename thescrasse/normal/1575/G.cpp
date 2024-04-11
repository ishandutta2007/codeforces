#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll mb[maxn];
vector<ll> dv[maxn];

struct rb_array {
    ll _f[maxn];
    vector<ll> v;

    rb_array() {
        ll i;
        for (i = 0; i < maxn; i++) _f[i] = 0;
    }

    ll &f(ll p) {
        if (_f[p] == 0) v.pb(p);
        return _f[p];
    }

    ll calc() {
        ll r = 0;
        for (auto u : v) {
            r += (mb[u] * f(u) * f(u)); r %= mod; f(u) = 0;
        }
        return r;
    }

    void clean() {
        for (auto u : v) _f[u] = 0;
        v.clear();
    }
};

rb_array f;

ll solve(ll d) {
    ll i, r;
    for (i = d; i <= n; i += d) {
        for (auto u : dv[a[i]]) f.f(u)++;
    }
    r = f.calc(); f.clean();
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 1; i < maxn; i++) mb[i] = i;
    for (i = 1; i < maxn; i++) {
        for (j = 2 * i; j < maxn; j += i) mb[j] -= mb[i];
    }

    for (i = 1; i < maxn; i++) {
        if (mb[i] == 0) continue;
        for (j = i; j < maxn; j += i) dv[j].pb(i);
    }

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        if (mb[i] == 0) continue;
        res += (mb[i] * solve(i)); res %= mod;
    }

    cout << res << nl;

    return 0;
}