#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100;
int cnt0[N], cnt1[N];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(cnt0, 0, sizeof(cnt0));
    memset(cnt1, 0, sizeof(cnt1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            int d1 = i + j;
            int d2 = (n - 1 - i) + (m - 1 - j);
            if (d1 == d2) continue;
            int val = min(d1, d2);
            if (v == 0) cnt0[val]++;
            else cnt1[val]++;
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) res += min(cnt0[i], cnt1[i]);
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}