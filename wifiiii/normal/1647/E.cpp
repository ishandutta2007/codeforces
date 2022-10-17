#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), a(n), deg(n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i], --p[i];
        deg[p[i]]++;
    }
    for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
    if(*max_element(a.begin(), a.end()) < n) {
        for(int i : a) cout << i + 1 << ' '; cout << '\n';
        return 0;
    }
    int ept = 0, mx = 0;
    for(int i = 0; i < n; ++i) {
        if(!deg[i]) {
            assert(a[i] >= n);
            ++ept;
            mx = max(mx, a[i]);
        }
    }
    int cyc = (mx - n + 1) / ept;
    vector<int> vis(n);
    for(int i = 0; i < n; ++i) {
        if(a[i] < n) vis[a[i]] = 1;
    }
    set<int> res;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) res.insert(i);
    }
    vector<vector<int>> f(n, vector<int>(30));
    for(int i = 0; i < n; ++i) {
        f[i][0] = p[i];
    }
    for(int i = 1; i < 30; ++i) {
        for(int j = 0; j < n; ++j) {
            f[j][i] = f[f[j][i - 1]][i - 1];
        }
    }
    for(int i = 0; i < n; ++i) {
        int k = i;
        for(int j = 29; j >= 0; --j) {
            if(cyc >> j & 1) {
                k = f[k][j];
            }
        }
        p[i] = k;
    }
    vector<int> used(n);
    for(int i = 0; i < n; ++i) {
        if(!used[a[p[i]]]) {
            used[a[p[i]]] = 1;
            cout << a[p[i]] + 1 << ' ';
        } else {
            int x = *res.lower_bound(a[p[i]]);
            cout << x + 1 << ' ';
            res.erase(x);
        }
    }
    cout << '\n';
}