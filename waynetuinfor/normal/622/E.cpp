#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
vector<int> G[maxn];

vector<int> *dfs(int now, int fa, int d) {
    int c = 0;
    vector<int> *ret = new vector<int>();
    for (int u : G[now]) if (u != fa) {
        ++c;
        vector<int> *res = dfs(u, now, d + 1);
        if (res->size() > ret->size()) swap(ret, res);
        for (int i : *res) ret->push_back(i);
    }
    if (ret->size() == 0) ret->push_back(d);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    int ans = 0;
    for (int u : G[1]) {
        vector<int> *now = dfs(u, 1, 1);
        sort(now->begin(), now->end());
        int maxdep = 0;
        for (size_t p = 0; p < now->size(); ++p) {
            if ((*now)[p] > maxdep) maxdep = (*now)[p];
            else ++maxdep;
        }
        ans = max(ans, maxdep);
    }
    cout << ans << endl;
    return 0;
}