#include <bits/stdc++.h>
using namespace std;

const int maxn = 40;
long long adj[maxn];
map<string, int> z;

int convert(const string &s) {
    if (z.find(s) != z.end()) return z[s];
    int res = (int)z.size();
    return z[s] = res;
}

void add_edge(int i, long long x) {
    while (x) {
        int y = __builtin_ctzll(x & -x);
        if (adj[i] >> y & 1ll) {
            adj[i] ^= 1ll << y;
            adj[y] ^= 1ll << i;
        }
        x -= x & -x;
    }
}

int dfs(long long r, long long p) {
    if (__builtin_popcountll(p) == 0) 
        return __builtin_popcountll(r);
    int x = __builtin_ctzll(p & -p);
    long long c = p & ~adj[x];
    int ans = 0;
    while (c) {
        int y = __builtin_ctzll(c & -c);
        r |= 1ll << y;
        ans = max(ans, dfs(r, p & adj[y]));
        r ^= 1ll << y;
        p ^= 1ll << y;
        c -= c & -c;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i != j)
                adj[i] ^= 1ll << j;
        }
    }
    vector<int> v;
    vector<pair<int, int>> w;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t == 1) {
            v.push_back(i);
            continue;
        }
        string s; cin >> s;
        int x = convert(s);
        w.emplace_back(x, i);
    }
    v.push_back(n);
    int j = 0;
    for (int i = 0; i + 1 < (int)v.size(); ++i) {
        long long prv = 0;
        while (j < (int)w.size() && w[j].second < v[i + 1]) {
            add_edge(w[j].first, prv);
            prv |= 1ll << w[j].first;
            ++j;
        }
    }
    long long r = 0, p = 0;
    for (int i = 0; i < m; ++i) p ^= 1ll << i;
    printf("%d\n", dfs(r, p));
}