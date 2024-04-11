#include <bits/stdc++.h>
using namespace std;

set<int> component;
vector<vector<int>> sto;
vector<int> par;

int find(int x) {
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

vector<int> to_erase;

void merge(int x, int y) {
    int u = find(x), v = find(y);
    if(sto[u].size() < sto[v].size())
        swap(u, v);
    sto[u].insert(sto[u].end(), sto[v].begin(), sto[v].end());
    sto[v].clear();
    to_erase.push_back(v);
    par[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<set<int>> in(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        in[x].insert(y);
        in[y].insert(x);
    }
    sto.resize(n);
    for(int i = 0; i < n; i++)
        sto[i].push_back(i);
    par.resize(n);
    iota(par.begin(), par.end(), 0);

    for(int i = 0; i < n; i++) {
        component.insert(i);
        to_erase.clear();
        for(int x : component) {
            if(x == i) continue;
            for(int y : sto[x]) {
                if(in[i].count(y)) continue;
                merge(i, y);
                break;
            }
        }
        for(int x : to_erase)
            component.erase(x);
    }
    cout << component.size() << "\n";
    vector<int> ans;
    for(int x : component)
        ans.push_back(sto[x].size());
    sort(ans.begin(), ans.end());
    for(int x : ans)
        cout << x << " ";
    cout << "\n";
}