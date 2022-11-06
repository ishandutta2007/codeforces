#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
pair<int, int> st[20][maxn];
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) st[0][i] = make_pair(i, i);
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            if (a[st[i - 1][j].first] > a[st[i - 1][j + (1 << (i - 1))].first]) st[i][j].first = st[i - 1][j].first;
            else st[i][j].first = st[i - 1][j + (1 << (i - 1))].first;
            if (a[st[i - 1][j].second] < a[st[i - 1][j + (1 << (i - 1))].second]) st[i][j].second = st[i - 1][j].second;
            else st[i][j].second = st[i - 1][j + (1 << (i - 1))].second;
        }
    }
    while (m--) {
        int l, r, x; cin >> l >> r >> x; --l, --r;
        int p = 31 - __builtin_clz(r - l + 1);
        if (a[st[p][l].first] != x) cout << st[p][l].first + 1 << endl;
        else if (a[st[p][r - (1 << p) + 1].first] != x) cout << st[p][r - (1 << p) + 1].first + 1 << endl;
        else if (a[st[p][l].second] != x) cout << st[p][l].second + 1 << endl;
        else if (a[st[p][r - (1 << p) + 1].second] != x) cout << st[p][r - (1 << p) + 1].second + 1 << endl;
        else cout << "-1" << endl;
    }
    return 0;
}