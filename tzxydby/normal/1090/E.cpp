#include <bits/stdc++.h>

using namespace std;

const int N = 64;

int u = 0;
int used[N];
bool f[N];
vector<int> g[N];

vector<pair<int, int> > ans;

void init() {
    for (int i = 0; i < N; ++i) {
        f[i] = false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((abs(i % 8 - j % 8) == 1 && abs(i / 8 - j / 8) == 2) ||
                (abs(i % 8 - j % 8) == 2 && abs(i / 8 - j / 8) == 1)) {
                    g[i].push_back(j);
                }
        }
    }
}

bool dfs(int v, int w, vector<int> &path) {
    path.push_back(v);
    used[v] = u;
    if (v >= w && f[v]) {
        return true;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to] < u) {
            if (dfs(to, w, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

void move(vector<int>& path) {
    int last = 0;
    for (int i = 0; i < path.size(); ++i) {
        if (f[path[i]]) {
            for (int j = i - 1; j >= last; --j) {
                ans.push_back({path[j + 1], path[j]});
            }
            last = i;
        }
    }
    f[path.back()] = false;
    f[path[0]] = true;
}

string get(int v) {
    string res;
    res += char('a' + v % 8);
    res += char('1' + v / 8);
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char a, b;
        cin >> a >> b;
        int v = (a - 'a') + (b - '1') * 8;
        f[v] = true;
    }
    for (int i = 0; i < n; ++i) {
        u++;
        vector<int> path;
        dfs(i, i, path);
        move(path);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << get(ans[i].first) << "-" << get(ans[i].second) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}