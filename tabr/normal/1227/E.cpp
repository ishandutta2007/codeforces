#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = '.' + s[i] + '.';
    }
    s[0] = s[n + 1] = string(m + 2, '.');
    vector<vector<int>> d(n + 2, vector<int>(m + 2, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (s[i][j] == '.') {
                d[i][j] = 0;
                pq.push({0, {i, j}});
            }
        }
    }
    while (!pq.empty()) {
        int dis = pq.top().first;
        int i, j;
        tie(i, j) = pq.top().second;
        pq.pop();
        if (dis > d[i][j]) continue;
        for (int di = -1; di <= 1; di++) {
            if (i == 0 && di == -1) continue;
            if (i == n + 1 && di == 1) continue;
            for (int dj = -1; dj <= 1; dj++) {
                if (j == 0 && dj == -1) continue;
                if (j == m + 1 && dj == 1) continue;
                if (d[i + di][j + dj] > d[i][j] + 1) {
                    d[i + di][j + dj] = d[i][j] + 1;
                    pq.push({d[i + di][j + dj], {i + di, j + dj}});
                }
            }
        }
    }
    int mx = 0;
    vector<vector<pair<int, int>>> x(2000);
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            mx = max(mx, d[i][j]);
            if (d[i][j] > 0) {
                x[d[i][j]].emplace_back(i, j);
            }
        }
    }
    vector<vector<int>> e;
    int ans = mx;

    int lo = 1, hi = mx + 1;
    while (lo + 1 < hi) {
        e = vector<vector<int>>(n + 2, vector<int>(m + 2));
        for (int i = 0; i < n + 2; i++) e[i][0] = e[i][m + 1] = 1e9;
        for (int i = 0; i < m + 2; i++) e[0][i] = e[n + 1][i] = 1e9;
        int mid = (lo + hi) / 2;
        queue<pair<int, int>> que;
        for (auto p : x[mid]) {
            if (d[p.first][p.second] == mid) {
                que.push({p.first, p.second});
                e[p.first][p.second] = mid;
                ans = mid;
            }
        }
        int tmp = mid - 1;
        while (que.size() && tmp) {
            for (int jj = que.size(); jj > 0; jj--) {
                int i, j;
                tie(i, j) = que.front();
                que.pop();
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (e[i + di][j + dj] != mid) {
                            e[i + di][j + dj] = mid;
                            que.push({i + di, j + dj});
                        }
                    }
                }
            }
            tmp--;
        }
        bool ok = true;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (d[i][j] != 0 && d[i][j] < mid && e[i][j] == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    /*
    debug(mx);
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cerr << e[i][j] << " ";
        }
        cerr << '\n';
    }
*/
    ans = lo - 1;
    vector<string> res(n, string(m, '.'));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'X') {
                if (d[i][j] > ans) {
                    res[i - 1][j - 1] = 'X';
                }
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}