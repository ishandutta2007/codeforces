#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
vector<int> G[maxn];
int cnt[26][maxn];
int d[maxn], tin[maxn], tout[maxn], t, md;

void dfs(int now, int dep) {
    md = max(md, dep);
    d[now] = dep;
    tin[now] = ++t;
    for (int u : G[now]) dfs(u, dep + 1);
    tout[now] = t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].emplace_back(i);
    }
    string s; cin >> s;
    dfs(1, 0);
#define nd G
    vector<int> nd;
    for (int i = 1; i <= n; ++i) nd.emplace_back(i);
    sort(nd.begin(), nd.end(), [&](const int& a, const int& b) { return d[a] == d[b] ? tin[a] < tin[b] : d[a] < d[b]; });
    cnt[s[nd[0] - 1] - 'a'][0]++;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) cnt[j][i] = cnt[j][i - 1];
        cnt[s[nd[i] - 1] - 'a'][i]++;
    }
    while (m--) {
        int v, h; cin >> v >> h; --h;
        auto a = lower_bound(nd.begin(), nd.end(), h, [&](const int& aa, const int& bb) { return d[aa] < bb; });
        auto b = lower_bound(nd.begin(), nd.end(), h + 1, [&](const int& aa, const int& bb) { return d[aa] < bb; });
        auto itl = lower_bound(a, b, tin[v], [&](const int& aa, const int& bb) { return tin[aa] < bb; });
        auto itr = lower_bound(a, b, tout[v], [&](const int& aa, const int& bb) { return tin[aa] < bb; });
        if (itr != nd.end() && (tin[*itr] > tout[v] || d[*itr] > h)) --itr;
        if (itr == nd.end()) --itr;
        auto ib = nd.begin(); --ib;
        if (itl == nd.end() || d[*itl] > h) { cout << "Yes\n"; continue; }
        if (itr == ib) { cout << "Yes" << endl; continue; }
        int o = 0, e = 0;
        for (int i = 0; i < 26; ++i) {
            int c = cnt[i][itr - nd.begin()] - (itl - nd.begin() == 0 ? 0 : cnt[i][itl - nd.begin() - 1]);
            if (c & 1) ++o;
            else ++e;
        }
        if (o <= 1) cout << "Yes\n";
        else cout << "No\n";
    }
#undef nd
    return 0;
}