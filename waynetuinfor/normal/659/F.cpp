#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int a[maxn][maxn], n, m, fin[maxn][maxn];
bool v[maxn * maxn], add[maxn][maxn];
vector<pair<int, int>> ans;

struct Dsu {
    int p[maxn * maxn], sz[maxn * maxn];
    void init() {
        for (int i = 0; i < maxn * maxn; ++i) {
            p[i] = i; sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x; sz[x] += sz[y];
    }
    int size(int x) {
        return sz[find(x)];
    }
} dsu;

int get(int i, int j) {
    return i * m + j;
}

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int x, int y, long long d) {
    if (ans.size() == d) return; 
    ans.push_back(make_pair(x, y));
    v[get(x, y)] = true;
    for (int i = 0; i < 4; ++i) {
        if (check(x + dx[i], y + dy[i])) {
            if (dsu.find(get(x, y)) == dsu.find(get(x + dx[i], y + dy[i]))) 
                if (!v[get(x + dx[i], y + dy[i])]) dfs(x + dx[i], y + dy[i], d);
        }
    }
}

void answer(int x, int y, long long d) {
    dfs(x, y, d);
    for (auto i : ans) fin[i.first][i.second] = a[x][y];
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << fin[i][j] << ' '; 
        cout << endl;
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long x; cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pos.push_back(make_pair(i, j));
    sort(pos.begin(), pos.end(), [&](const pair<int, int>& i, const pair<int, int>& j) { return a[i.first][i.second] > a[j.first][j.second]; });
    dsu.init();
    for (int i = 0; i < pos.size(); ++i) {
        for (int j = 0; j < 4; ++j) if (check(pos[i].first + dx[j], pos[i].second + dy[j])) {
            if (add[pos[i].first + dx[j]][pos[i].second + dy[j]]) {
                dsu.merge(get(pos[i].first, pos[i].second), get(pos[i].first + dx[j], pos[i].second + dy[j]));
            }
        }
        if (x % a[pos[i].first][pos[i].second] == 0) {
            long long d = x / a[pos[i].first][pos[i].second];
            if (dsu.size(get(pos[i].first, pos[i].second)) >= d) answer(pos[i].first, pos[i].second, d);
        }
        add[pos[i].first][pos[i].second] = true;
    }
    cout << "NO" << endl;
    return 0;
}