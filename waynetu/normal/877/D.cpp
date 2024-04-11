#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
string s[maxn];
int ans[maxn * maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    if (x1 == x2 && y1 == y2) {
        cout << "0" << endl;
        return 0;
    }
    queue<int> q; q.push(x1 * m + y1);
    while (q.size()) {
        int now = q.front(); q.pop();
        int r = now / m, c = now % m;
        for (int i = 1; i <= k; ++i) {
            if (c + i >= m) break;
            if (s[r][c + i] == '#') break;
            if (!ans[r * m + (c + i)]) {
                ans[r * m + c + i] = ans[now] + 1;
                if (r == x2 && c + i == y2) return cout << ans[now] + 1 << endl, 0;
                q.push(r * m + c + i);
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (c - i < 0) break;
            if (s[r][c - i] == '#') break;
            if (!ans[r * m + (c - i)]) {
                ans[r * m + c - i] = ans[now] + 1;
                if (r == x2 && c - i == y2) return cout << ans[now] + 1 << endl, 0;
                q.push(r * m + c - i);
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (r + i >= n) break;
            if (s[r + i][c] == '#') break;
            if (!ans[(r + i) * m + c]) {
                ans[(r + i) * m + c] = ans[now] + 1;
                if (r + i == x2 && c == y2) return cout << ans[now] + 1 << endl, 0;
                q.push((r + i) * m + c);
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (r - i < 0) break;
            if (s[r - i][c] == '#') break;
            if (!ans[(r - i) * m + c]) {
                ans[(r - i) * m + c] = ans[now] + 1;
                if (r - i == x2 && c == y2) return cout << ans[now] + 1 << endl, 0;
                q.push((r - i) * m + c);
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}