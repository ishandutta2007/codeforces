#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxv = 2e6 + 10;
int a[maxn], ans[maxn], dep[maxn];
vector<int> G[maxn], pr, fr[maxv];
unordered_map<int, int> cur;

void sieve() {
    bitset<maxv> v;
    for (int i = 2; i < maxv; ++i) if (!v[i]) {
        fr[i].push_back(i);
        for (int j = i + i; j < maxv; j += i) {
            v[j] = true;
            fr[j].push_back(i);
        }
    } 
}

void dfs(int now, int fa, int d = 1) {
    dep[now] = d;
    unordered_map<int, int> tmp;
    for (int p : fr[a[now]]) {
        // cout << "p = " << p << endl;
        // cout << "cur[p] = " << cur[p] << endl;
        ans[now] = (ans[now] == -1 || dep[ans[now]] < dep[cur[p]] ? cur[p] : ans[now]);
        tmp[p] = cur[p]; cur[p] = now;
    }
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
    }
    for (int p : fr[a[now]]) {
        cur[p] = tmp[p];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    memset(ans, -1, sizeof(ans));
    dfs(1, 0);
    while (q--) {
        int t; cin >> t; 
        if (t == 1) {
            int k; cin >> k;
            cout << (ans[k] == -1 || ans[k] == 0 ? -1 : ans[k]) << endl;
        } else {
            int k, v; cin >> k >> v;
            cur.clear(); a[k] = v;
            memset(ans, -1, sizeof(ans));
            dfs(1, 0);
        }
    }
    return 0;
}