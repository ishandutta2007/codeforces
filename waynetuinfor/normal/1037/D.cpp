#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn], k[maxn];
int dt[maxn], a[maxn], fa[maxn], ch[maxn];
int pos[maxn], st[maxn], ed[maxn];
bool v[maxn];

void dfs(int x, int p, int d) {
    dt[x] = d;
    for (int u : g[x]) if (u != p) 
        dfs(u, x, d + 1), fa[u] = x, ++ch[x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    for (int i = 0; i < n; ++i) cin >> a[i], pos[a[i]] = i;
    if (dt[a[0]] != 0) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        if (dt[a[i]] != dt[a[i - 1]] && dt[a[i]] != dt[a[i - 1]] + 1) {
            cout << "No" << endl;
            return 0;
        }
        k[dt[a[i]]].push_back(a[i]); 
        if (dt[a[i]] == dt[a[i - 1]] + 1) {
            st[dt[a[i]]] = i;
            ed[dt[a[i - 1]]] = i - 1;
        }
    }
    int md = *max_element(dt + 1, dt + n + 1);
    ed[md] = n - 1;
    for (int i = 0; i < md; ++i) {
        int ptr = st[i + 1];
        for (int j = 0; j < k[i].size(); ++j) {
            int x = k[i][j];
            int l = maxn, r = -1, cnt = 0;
            for (int u : g[x]) if (fa[u] == x) {
                l = min(l, pos[u]);
                r = max(r, pos[u]);
                ++cnt;
            }
            if (cnt == 0) continue;
            if (r - l + 1 != cnt) {
                cout << "No" << endl;
                return 0;
            }
            if (l != ptr) {
                cout << "No" << endl;
                return 0;
            }
            ptr += cnt;
        }
    } 
    cout << "Yes" << endl;
}