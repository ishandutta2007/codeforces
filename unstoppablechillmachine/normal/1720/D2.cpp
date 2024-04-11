#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 1.5e7 + 10;
int go[N][2], subtree_max[N][2], cnt = 1;
void relax(int id, int xor_id, int value) {
    int v = 1;
    for (int i = 29; i >= 0; i--) {
        if (!go[v][(xor_id >> i) & 1]) {
            go[v][(xor_id >> i) & 1] = ++cnt;
        }
        v = go[v][(xor_id >> i) & 1];
        subtree_max[v][(id >> i) & 1] = max(subtree_max[v][(id >> i) & 1], value);
    }
}

void clear() {
    for (int i = 1; i <= cnt; i++) {
        go[i][0] = go[i][1] = subtree_max[i][0] = subtree_max[i][1] = 0;
    }
    cnt = 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        clear();
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        vector<int> dp(n, 1);
        relax(a[0], a[0], 1);
        int answer = 1;
        for (int i = 1; i < n; i++) {
            int v = 1, mx = 0;
            for (int j = 29; j >= 0; j--) {
                int nxt = ((a[i] ^ i) >> j) & 1;
                mx = max(mx, subtree_max[go[v][nxt ^ 1]][(i >> j) & 1]);
                v = go[v][nxt];
            }
            dp[i] = mx + 1;
            relax(a[i], a[i] ^ i, dp[i]);
            answer = max(answer, dp[i]);
        }
        cout << answer << '\n';
    }
    return 0;
}