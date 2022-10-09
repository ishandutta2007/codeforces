#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010
#define sq 550

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll l, r, f[maxn], ff[maxn], rs[maxn], q, mx;
vector<array<ll, 3>> v;

bool cmp(array<ll, 3> a, array<ll, 3> b) {
    if (a[0] / sq != b[0] / sq) return (a[0] / sq < b[0] / sq);
    return (a[1] < b[1]);
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
    v.pb({0, 0});
    for (i = 1; i <= q; i++) {
        cin >> l >> r; v.pb({l, r, i}); rs[i] = r - l + 1;
    }

    sort(v.begin(), v.end(), cmp);

    l = 1; r = 0;
    for (auto u : v) {
        while (u[0] < l) {
            l--; ff[f[a[l]]]--; f[a[l]]++; ff[f[a[l]]]++; mx = max(mx, f[a[l]]);
        }
        while (u[1] > r) {
            r++; ff[f[a[r]]]--; f[a[r]]++; ff[f[a[r]]]++; mx = max(mx, f[a[r]]);
        }
        while (u[0] > l) {
            ff[f[a[l]]]--;
            if (ff[f[a[l]]] == 0 && mx == f[a[l]]) mx--;
            f[a[l]]--; ff[f[a[l]]]++; l++;
        }
        while (u[1] < r) {
            ff[f[a[r]]]--;
            if (ff[f[a[r]]] == 0 && mx == f[a[r]]) mx--;
            f[a[r]]--; ff[f[a[r]]]++; r--;
        }
        rs[u[2]] = max((ll)1, 2 * mx - rs[u[2]]);
    }

    for (i = 1; i <= q; i++) {
        cout << rs[i] << nl;
    }

    return 0;
}