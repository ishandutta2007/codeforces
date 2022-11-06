#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, INF = 10000000;
int ans[maxn << 1];
bool a[maxn << 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, s; cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> s, a[s] = true;
    queue<int> q;
    fill(ans, ans + maxn * 2, INF);
    for (int i = 0; i <= 1000; ++i) if (a[i]) q.push(i - n + maxn), ans[i - n + maxn] = 1;
    while (q.size()) {
        if (ans[maxn] != INF) return cout << ans[maxn] << '\n', 0;
        int p = q.front(); q.pop();
        for (int i = 0; i <= 1000; ++i) {
            if (!a[i]) continue;
            int nxt = p + i - n;
            if (nxt < 0 || nxt > 2010) continue;
            if (ans[nxt] > ans[p] + 1) {
                q.push(nxt);
                ans[nxt] = ans[p] + 1;
            }
        }
    }
    cout << "-1\n", 0;
    return 0;
}