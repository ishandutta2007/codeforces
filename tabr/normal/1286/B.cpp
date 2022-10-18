#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

vector<vector<int>> sbs(2020);
vector<int> c(2020, -1);
bool b;

vector<int> dfs(int v) {
    vector<int> res;
    if (b) return res;
    for (auto u : sbs[v]) {
        vector<int> x = dfs(u);
        res.insert(res.end(), x.begin(), x.end());
    }
    if (c[v] > res.size())
        b = true;
    else
        res.insert(res.begin() + c[v], v);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, root;
    cin >> n;
    b = false;
    rep(i, 0, n) {
        int p;
        cin >> p >> c[i + 1];
        if (p == 0)
            root = i + 1;
        else
            sbs[p].emplace_back(i + 1);
    }
    vector<int> z = dfs(root);
    if (b) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> ans(n);
    rep(i, 0, n) ans[z[i] - 1] = i + 1;
    for (auto x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}