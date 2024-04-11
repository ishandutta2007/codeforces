#include <bits/stdc++.h>
using namespace std;

const int mods[] = { 479001599, 433494437, 1073807359, 1442968193, 715827883, 1000000007, 1000000009 };
const int ps[] = { 101, 233, 457, 173, 211, 131, 563 };
const int maxn = 1e6 + 10;
int mod[2], p[2], dp[2][maxn];
string s[maxn];
bool v[maxn];

int cadd(int a, int b, int p) { return (a += b) >= p ? a - p : a; }
int cmul(int a, int b, int p) { return a * 1ll * b % p; }

struct hashpair {
    int hs[2];
    hashpair(char c) { hs[0] = c; hs[1] = c; }
    void add(char c) { for (int i = 0; i < 2; ++i) hs[i] = cadd(cmul(hs[i], p[i], mod[i]), c, mod[i]); }
    hashpair() {}
    bool operator==(const hashpair &rhs) const { return hs[0] == rhs.hs[0] && hs[1] == rhs.hs[1]; }
    bool operator<(const hashpair &rhs) const { return tie(hs[0], hs[1]) < tie(rhs.hs[0], rhs.hs[1]); }
};

namespace std { template<> struct hash<hashpair> { long long operator()(const hashpair &h) const { return h.hs[0] << 30 | h.hs[1]; } }; }

vector<int> graph[maxn];
unordered_map<hashpair, int> all;

void dfs(int now, int fa) {
    v[now] = true;
    dp[1][now] = 1; dp[0][now] = 0;
    for (int u : graph[now]) if (u != fa && !v[u]) {
        dfs(u, now);
        dp[1][now] += dp[0][u];
        dp[0][now] += max(dp[1][u], dp[0][u]);
    }
}

void add(hashpair val) {
    if (all.find(val) != all.end()) return;
    int sz = (int)all.size();
    all[val] = sz;
}

int get(hashpair val) {
    if (all.find(val) == all.end()) return -1;
    return all[val];
}

void add_edge(hashpair a, hashpair b) {
    int u = get(a), v = get(b);
    if (min(u, v) == -1) return;
    graph[u].push_back(v); graph[v].push_back(u);
    // cout << "connect a = " << a << " b = " << b << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr)); 
    mod[0] = mods[rand() % 7], p[0] = ps[rand() % 7];
    mod[1] = mods[rand() % 7], p[1] = ps[rand() % 7];
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> s[i];
        hashpair now, prv;
        for (int i = 0; i < n; ++i) {
            now = hashpair(s[i][0]);
            add(now);
            for (int j = 1; j < (int)s[i].size(); ++j) now.add(s[i][j]), add(now);
        }
        for (int i = 0; i < (int)all.size(); ++i) graph[i].clear();
        for (int i = 0; i < n; ++i) if (s[i].size() > 1) {
            prv = hashpair(s[i][1]), now = hashpair(s[i][0]), now.add(s[i][1]);
            add_edge(now, prv);
            for (int j = 2; j < (int)s[i].size(); ++j) {
                prv.add(s[i][j]); now.add(s[i][j]);
                add_edge(now, prv);
            }
        }
        int ans = 0;
        for (int i = 0; i < (int)all.size(); ++i) v[i] = false;
        for (int i = 0; i < (int)all.size(); ++i) if (!v[i]) {
            dfs(i, -1);
            ans += max(dp[0][i], dp[1][i]);
        }
        cout << ans << endl;
        all.clear();
    }
    return 0;
}