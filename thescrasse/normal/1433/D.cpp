#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, sz[maxn], parent[maxn];

ll find(ll x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void merge(ll a, ll b) {
    a = find(a); b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a; sz[a] += sz[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; flag[0] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i] != a[i - 1]) flag[0] = 1;
        }

        if (flag[0] == 0) {
            cout << "NO" << nl; continue;
        }

        cout << "YES" << nl;

        for (i = 0; i < n; i++) {
            parent[i] = i; sz[i] = 1;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i] == a[j]) continue;
                if (same(i, j)) continue;
                merge(i, j);
                cout << i + 1 << ' ' << j + 1 << nl;
            }
        }
    }

    return 0;
}