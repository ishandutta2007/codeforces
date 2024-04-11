#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int a[maxn], n, c;
vector<pair<pair<int, int>, int>> ans;

struct sparse {
    pair<int, int> data[20][maxn];
    void init() {
        for (int i = 0; i < n; ++i) data[0][i] = make_pair(a[i + 1], i + 1);
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) data[i][j] = min(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
        }
    }
    pair<int, int> query(int l, int r) {
        --l; --r;
        int p = 31 - __builtin_clz(r - l + 1);
        return min(data[p][l], data[p][r - (1 << p) + 1]);
    }
} sp;

void solve(int l, int r, int to) {
    if (l > r) return;
    int v, p; tie(v, p) = sp.query(l, r);
    c += v - to;
    ans.emplace_back(make_pair(l, r), v - to);
    solve(l, p - 1, v); solve(p + 1, r, v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sp.init();
    solve(1, n, 0); 
    cout << c << endl;
    for (auto i : ans) {
        while (i.second--) cout << i.first.first << ' ' << i.first.second << '\n';
    }
    return 0;
}