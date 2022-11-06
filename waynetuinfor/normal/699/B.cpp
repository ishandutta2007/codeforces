#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
string s[maxn];
int x[maxn], y[maxn];
bool v[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (s[i][j] == '*') vec.push_back(make_pair(i, j));
    }
    for (auto i : vec) x[i.first]++, y[i.second]++, v[i.first][i.second] = true;
    if (vec.empty()) return cout << "YES\n1 1\n", 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (x[i] + y[j] >= (int)vec.size() + (int)v[i][j]) {
            cout << "YES\n";
            cout << i + 1 << ' ' << j + 1 << '\n';
            return 0;
        }
    }
    return cout << "NO\n", 0;
}