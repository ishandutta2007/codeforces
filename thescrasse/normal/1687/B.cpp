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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll x, y;
vector<array<ll, 2>> v;

ll ask() {
    ll i, r;
    cout << "? ";
    for (i = 1; i <= m; i++) cout << a[i];
    cout << nf;
    cin >> r; return r;
}

void clm(ll x) {
    cout << "!" _ x << nf; exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= m; j++) {
            a[j] = (i == j);
        }
        b[i] = ask();
    }

    for (i = 1; i <= m; i++) v.pb({b[i], i});
    sort(v.begin(), v.end());

    for (i = 1; i <= m; i++) a[i] = 0;
    for (auto [w, id] : v) {
        a[id] = 1;
        y = ask();
        if (y - x == w) res += w;
        x = y;
    }

    clm(res);

    return 0;
}