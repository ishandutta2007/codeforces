#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string s[maxn];
pair<int, int> st, ed;
bool v[4][4][maxn][maxn];
int n, m;

bool dfs(int, int, int, int);
bool check(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'S') st = make_pair(i, j);
        if (s[i][j] == 'T') ed = make_pair(i, j);
    }
    bool ans = false;
    if (st.first + 1 < n && s[st.first + 1][st.second] != '*')   ans |= dfs(st.first + 1, st.second, 0, 0);
    if (st.first - 1 >= 0 && s[st.first - 1][st.second] != '*')  ans |= dfs(st.first - 1, st.second, 1, 0);
    if (st.second + 1 < m && s[st.first][st.second + 1] != '*')  ans |= dfs(st.first, st.second + 1, 2, 0);
    if (st.second - 1 >= 0 && s[st.first][st.second - 1] != '*') ans |= dfs(st.first, st.second - 1, 3, 0);
    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}

bool dfs(int x, int y, int dir, int turn) {
    if (turn > 2) return false;
    if (make_pair(x, y) == ed) return true;
    v[dir][turn][x][y] = true;
    bool ret = false;
    for (int i = 0; i < 4; ++i) if (check(x, y, i)) {
        if (i == dir) if (!v[i][turn][x + dx[i]][y + dy[i]]) {
            if (s[x + dx[i]][y + dy[i]] != '*') ret |= dfs(x + dx[i], y + dy[i], i, turn);
        }
        if (i != dir) if (!v[i][turn + 1][x + dx[i]][y + dy[i]]) {
            if (s[x + dx[i]][y + dy[i]] != '*') ret |= dfs(x + dx[i], y + dy[i], i, turn + 1);
        }
    }
    return ret;
}

bool check(int x, int y, int dir) {
    return x + dx[dir] < n && x + dx[dir] >= 0 && y + dy[dir] < m && y + dy[dir] >= 0;
}