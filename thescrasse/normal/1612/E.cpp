#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll f[maxn], l;
array<ll, 2> r;
vector<array<ll, 2>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    l = 1;
    for (i = 1; i <= 20; i++) {
        l = (l * i) / __gcd(l, i);
    }

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    r = {-INF, -INF};
    for (i = 1; i <= 20; i++) {
        v.clear();
        for (j = 0; j < maxn; j++) f[j] = 0;
        for (j = 1; j <= n; j++) f[a[j]] += min(i, b[j]);
        for (j = 0; j < maxn; j++) {
            if (f[j] == 0) continue;
            v.pb({f[j], j});
        }

        if (v.size() < i) continue;
        sort(v.begin(), v.end()); reverse(v.begin(), v.end());

        k = 0;
        for (j = 0; j <= i - 1; j++) k += v[j][0];
        r = max(r, {k * l / i, i});
        // cout << "i, k =" _ i _ k << nl;
    }

    i = r[1];
    cout << i << nl;
    v.clear();
    for (j = 0; j < maxn; j++) f[j] = 0;
    for (j = 1; j <= n; j++) f[a[j]] += min(i, b[j]);
    for (j = 0; j < maxn; j++) {
        if (f[j] == 0) continue;
        v.pb({f[j], j});
    }

    sort(v.begin(), v.end()); reverse(v.begin(), v.end());

    for (j = 0; j <= i - 1; j++) cout << v[j][1] << ' ';
    cout << nl;

    return 0;
}