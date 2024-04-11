#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dfn(n), par(n); int cnt = 0;
    function<void(int,int)> dfs = [&](int u, int fa) {
        dfn[cnt++] = u;
        for(int v : g[u]) {
            if(v == fa) continue;
            par[v] = u;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    auto ask = [&](vector<int> a) {
        cout << "? " << a.size() << " ";
        for(int i : a) cout << i + 1 << " ";
        cout << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    int qwq = ask(a);
    int lo = 1, hi = n - 1;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(ask(vector<int>(dfn.begin(), dfn.begin() + mid + 1)) == qwq) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << "! " << par[dfn[lo]] + 1 << " " << dfn[lo] + 1 << '\n';
}