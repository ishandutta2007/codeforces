#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<pair<int, int>> G[maxn];
bool v[maxn], used[maxn];
set<pair<int, int>> ed;

struct ans {
    int a, b, c;
    ans(int a, int b, int c): a(a), b(b), c(c) {}
};

vector<ans> vec;

void dfs(int now, int fa) {
    v[now] = true;
    int queued = 0, eid = -1;
    for (auto u : G[now]) if (u.first != fa) {
        if (!v[u.first]) dfs(u.first, now);
        if (used[u.second] || ed.count(minmax(now, u.first))) continue;
        if (queued) {
            vec.push_back(ans(queued, now, u.first));
            ed.insert(minmax(queued, now));
            ed.insert(minmax(now, u.first));
            queued = 0;
            eid = -1;
        } else queued = u.first, eid = u.second;
    } 
    if (queued && fa > 0 && ed.count(minmax(queued, now)) == 0 && ed.count(minmax(now, fa)) == 0) {
        vec.push_back(ans(queued, now, fa));
        ed.insert(minmax(queued, now));
        ed.insert(minmax(now, fa));
        used[eid] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b, i); G[b].emplace_back(a, i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) dfs(i, 0);
    } 
    cout << vec.size() << endl;
    for (ans i : vec) cout << i.a << ' ' << i.b << ' ' << i.c << endl;
    return 0;
}