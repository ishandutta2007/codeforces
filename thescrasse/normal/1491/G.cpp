// 1491G
// Switch and Flip

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
ll parent[maxn], sz[maxn], d1[maxn], d2[maxn], st[maxn];
bool vis[maxn];
vector<array<ll, 2>> rs;

void dfs(ll s) {
    if (vis[s]) return;
    vis[s] = true; sz[k]++;
    dfs(b[s]);
}

void swp(ll x, ll y) {
    // cout << "swp " << x _ y << nl;
    rs.pb({b[x], b[y]});
    swap(b[x], b[y]);
    parent[b[x]] = x; parent[b[y]] = y;
}

void solve_dirty(ll ty) {
    ll x, y;
    // cout << "solve_dirty " << ty << nl;
    if (sz[ty] == 2) {
        swp(d1[ty], d2[ty]); return;
    }
    // cout << d1[ty] _ parent[d1[ty]] << nl;
    // cout << d2[ty] _ parent[d2[ty]] << nl;
    if (parent[d1[ty]] == d2[ty]) swap(d1[ty], d2[ty]);
    x = parent[d1[ty]]; y = d1[ty];
    d1[ty] = x; sz[ty]--;
    swp(x, y);
    solve_dirty(ty);
}

void solve_clean(ll ty) {
    // cout << "solve_clean " << ty << nl;
    ll x, y, z;
    x = st[ty]; y = b[x]; z = b[y];
    d1[ty] = x; d2[ty] = z;
    swp(x, y); swp(y, z);
    solve_dirty(ty);
}

void merge_2(ll ty1, ll ty2) {
    // cout << "merge_2 " << ty1 _ ty2 << nl;
    ll x, y;
    x = st[ty1]; y = st[ty2];
    swp(x, y); d1[ty1] = x; d2[ty1] = y; sz[ty1] += sz[ty2];
    solve_dirty(ty1);
}

void merge_3(ll ty1, ll ty2, ll ty3) {
    // cout << "merge_3 " << ty1 _ ty2 _ ty3 << nl;
    ll x, y, z;
    x = st[ty1]; y = st[ty2]; z = st[ty3];
    swp(x, y); swp(y, z); d1[ty1] = x; d2[ty1] = z; sz[ty1] += sz[ty2] + sz[ty3];
    solve_dirty(ty1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; b[a[i]] = i; parent[i] = a[i];
    }

    for (i = 1; i <= n; i++) {
        if (!vis[i]) {
            st[k] = i; dfs(i); k++;
        }
    }

    if (k == 1) solve_clean(0);
    for (i = 0; i <= k - 2; i += 2) {
        if (i == k - 3) merge_3(i, i + 1, i + 2);
        else merge_2(i, i + 1);
    }

    cout << rs.size() << nl;
    for (auto u : rs) cout << u[0] _ u[1] << nl;

    return 0;
}