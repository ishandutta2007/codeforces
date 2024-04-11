#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        for(int j = 0; j < m; ++j) cin >> a[i][j];
        reverse(a[i].begin(), a[i].end());
    }
    int m;
    cin >> m;
    set<vector<int>> ban, vis;
    for(int i = 0; i < m; ++i) {
        vector<int> b(n);
        for(int j = 0; j < n; ++j) cin >> b[j], b[j] = a[j].size() - b[j];
        ban.insert(b);
    }
    priority_queue<pair<ll,vector<int>>> q;
    vector<int> init(n);
    q.push({0, init});
    while(!q.empty()) {
        auto [s, v] = q.top(); q.pop();
        if(ban.find(v) == ban.end()) {
            for(int i = 0; i < n; ++i) {
                cout << a[i].size() - v[i] << " ";
            }
            cout << endl;
            exit(0);
        }
        for(int i = 0; i < n; ++i) {
            if(v[i] + 1 < a[i].size()) {
                vector<int> nv = v;
                nv[i] += 1;
                ll ns = s + (a[i][nv[i]] - a[i][v[i]]);
                if(!vis.count(nv)) {
                    q.push({ns, nv});
                    vis.insert(nv);
                }
            }
        }
    }
}