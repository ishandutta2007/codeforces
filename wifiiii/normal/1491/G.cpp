#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), vis(n);
    for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<vector<int>> c;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        int cur = i;
        vector<int> tmp;
        while(!vis[cur]) {
            vis[cur] = 1;
            tmp.push_back(cur);
            cur = a[cur];
        }
        c.push_back(tmp);
    }
    vector<pair<int,int>> ans;
    auto go = [&](int i, int j) {
        ans.push_back({i, j});
        swap(a[i], a[j]);
        a[i] = -a[i];
        a[j] = -a[j];
    };
    while(c.size() > 1) {
        auto v1 = c.back(); c.pop_back();
        auto v2 = c.back(); c.pop_back();
        go(v1[0], v2[0]);
        for(int i = 1; i < v1.size(); ++i) {
            go(v2[0], v1[i]);
        }
        for(int i = 1; i < v2.size(); ++i) {
            go(v1[0], v2[i]);
        }
        go(v1[0], v2[0]);
    }
    if(c.size()) {
        auto v = c.back();
        if(v.size() == 2) {
            int p = 0;
            while(p != a[p]) ++p;
            go(v[1], p);
            go(v[0], p);
            go(v[1], p);
        } else if(v.size() > 1) {
            go(v[0], v[1]);
            for(int i = 2; i < v.size() - 1; ++i) {
                go(v[0], v[i]);
            }
            go(v[1], v.back());
            go(v[0], v.back());
            go(v[0], v[1]);
        }
    }
    for(int i = 0; i < n; ++i) assert(i == a[i]);
    assert(ans.size() <= n + 1);
    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
}