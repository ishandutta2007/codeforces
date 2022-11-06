#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int p[maxn];
bool v[maxn];

struct DisjointSet {
    int _djs[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) _djs[i] = i;
    }
    int find(int x) {
        if (x == _djs[x]) return x;
        return _djs[x] = find(_djs[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        _djs[x] = y;
    } 
} djs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, cycle = 0; cin >> n; 
    djs.init();
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        djs.merge(i, p[i]); 
    }
    for (int i = 1; i <= n; ++i) G[djs.find(i)].push_back(i);
    vector<int> c; 
    for (int i = 1; i <= n; ++i) {
        if (G[i].size() == 0) continue;
        int cur = G[i][0]; v[cur] = true;
        while (true) {
            if (v[p[cur]]) {
                c.push_back(cur);
                break;
            }
            v[p[cur]] = true;
            cur = p[cur];
        }
    }
    int con = -1, ans = 0;
    for (int i : c) if (i == p[i]) {
        con = i;
        break;
    }
    if (con == -1) con = c[0];
    for (int i : c) {
        if (p[i] != con) {
            ++ans;
            p[i] = con;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << '\n';
    return 0;
}