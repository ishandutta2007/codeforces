#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
string grid[maxn], s;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int n, m;
bool v[maxn];

bool ok(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m && grid[a][b] != '#';
}

bool check(vector<int> v) {
    int sx, sy, ex, ey;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') sx = i, sy = j;
            if (grid[i][j] == 'E') ex = i, ey = j;
        }
    }
    if (sx == ex && sy == ey) return true;
    for (int i = 0; i < s.length(); ++i) {
        sx += dx[v[s[i] - '0']], sy += dy[v[s[i] - '0']];
        if (!ok(sx, sy)) return false;
        if (sx == ex && sy == ey) break;
    }
    return sx == ex && sy == ey;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> grid[i];
    cin >> s;
    vector<int> v = { 0, 1, 2, 3 };
    int ans = 0;
    do {
        if (check(v)) ++ans;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}