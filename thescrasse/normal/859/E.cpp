// 859E
// Desk Disorder

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, parent[maxn], cn[maxn], cyc[maxn];

ll find(ll x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

ll f_cn(ll x) {
    return cn[find(x)];
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void f_nw(ll a, ll b) {
    a = find(a); b = find(b);
    if (cn[a] > cn[b]) swap(a, b);
    parent[a] = b;
    cn[b] += cn[a];
    cyc[b] = max(cyc[b], cyc[a]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;

    for (i = 1; i <= 2 * n; i++) {
        parent[i] = i; cn[i] = 1; cyc[i] = 0;
    }

    for (i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == b) {
            cyc[find(a)] = 2;
        } else if (same(a, b)) {
            cyc[find(a)] = max(cyc[find(a)], (ll)1);
        } else {
            f_nw(a, b);
        }
    }

    res = 1;
    for (i = 1; i <= 2 * n; i++) {
        if (find(i) == i && cn[i] > 1) {
            if (cyc[i] == 1) res *= 2;
            else if (cyc[i] == 0) res *= cn[i];
            res %= mod;
        }
    }

    cout << res;

    return 0;
}