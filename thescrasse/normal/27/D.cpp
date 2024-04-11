// 27D
// Ring Road 2

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<ll> adj[maxn];
bool visited[maxn], cl[maxn];

void dfs(ll s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (visited[u] && cl[s] == cl[u]) flag[1] = 1;
        cl[u] = (cl[s] + 1) % 2;
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; flag[1] = 0;
    for (i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }

    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            flag[0] = 0;
            if (a[i] < a[j] && a[j] < b[i]) flag[0]++;
            if (a[i] < b[j] && b[j] < b[i]) flag[0]++;
            if (a[i] == a[j] || b[i] == b[j]) flag[0] += 2;
            if (flag[0] == 1) {
                adj[i].pb(j); adj[j].pb(i);
            }
        }
    }

    for (i = 0; i < m; i++) {
        if (!visited[i]) {
            cl[i] = 0; dfs(i);
        }
    }

    if (flag[1] == 1) {
        cout << "Impossible";
    } else {
        for (i = 0; i < m; i++) {
            if (cl[i] == 0) cout << "i";
            else cout << "o";
        }
    }

    return 0;
}