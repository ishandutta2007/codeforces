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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p, x;
ll q, er[maxn], nc[maxn], zr[maxn];
vector<ll> pm;
multiset<ll> ms[20010];
map<ll, ll> mp[200010];

void fct(ll n, ll p) {
    ll i, x, k, a, b, m1, m2;
    vector<array<ll, 2>> v;

    x = n;
    while (x != 1) {
        // cout << x << nf;
        k = er[x];
        if (!v.empty() && v[(ll)v.size() - 1][0] == k) v[(ll)v.size() - 1][1]++;
        else v.pb({k, 1});
        x /= k;
    }

    for (auto u : v) {
        a = u[0]; b = u[1];
        m1 = (*(ms[nc[a]].begin()));
        if (zr[a] > 0) m1 = 0;
        k = mp[p][a]; mp[p][a] = k + b;
        if (k != 0) ms[nc[a]].erase(ms[nc[a]].find(k));
        ms[nc[a]].insert(k + b);
        if (k == 0) zr[a]--;
        m2 = (*(ms[nc[a]].begin()));
        if (zr[a] > 0) m2 = 0;
        // cout << a _ zr[a] << nl;
        for (i = 1; i <= m2 - m1; i++) {
            res *= a; res %= mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i < maxn; i++) er[i] = i;
    for (i = 2; i < maxn; i++) {
        if (er[i] != i) continue;
        for (j = 2 * i; j < maxn; j += i) er[j] = i;
    }

    k = 1;
    for (i = 2; i < maxn; i++) {
        if (er[i] == i) {
            pm.pb(i); nc[i] = k; k++; zr[i] = n;
        }
    }

    res = 1;
    for (i = 1; i <= n; i++) fct(a[i], i);
    // cout << res << nl;

    while (q--) {
        cin >> p >> x;
        fct(x, p);
        cout << res << nl;
    }

    return 0;
}