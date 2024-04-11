#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int x[maxn], l[maxn], r[maxn], ans[maxn];
vector<int> to[maxn], v[maxn];
bool used[maxn];

void check(int n, int m) {
    for (int i = 0; i < m; ++i) {
        int c[2] = { 0, 0 };
        for (int j : v[i]) ++c[ans[j]];
        if (abs(c[0] - c[1]) > 1) return;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << endl;
    exit(0);
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < m; ++i) cin >> l[i] >> r[i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (l[i] <= x[j] && r[i] >= x[j]) to[j].push_back(i), v[i].push_back(j);
        }
    }
    for (int i = 0; i < m; ++i) {
        sort(v[i].begin(), v[i].end(), [&](const int &a, const int &b) { return x[a] < x[b]; });
    }
    vector<int> ord(m); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) { return l[a] < l[b]; });
    int last = 1;
    for (int i = 0; i < ord.size(); ++i) {
        for (int j : v[ord[i]]) if (!used[j]) ans[j] = (last ^ 1), last ^= 1, used[j] = true;
    }
    check(n, m);
    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) { return r[a] > r[b]; });
    last = 1;
    memset(used, false, sizeof(used));
    for (int i = 0; i < ord.size(); ++i) {
        for (int j : v[ord[i]]) if (!used[j]) ans[j] = (last ^ 1), last ^= 1, used[j] = true;
    }
    check(n, m);
    cout << "-1" << endl;
}