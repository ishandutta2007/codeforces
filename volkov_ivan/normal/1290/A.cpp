#include <iostream>

using namespace std;

const int INF = 1e9 + 7, N = 4000;
int a[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = -1;
    for (int i = 0; i < n; i++) cin >> a[i];
    k = min(k, m - 1);
    for (int i = 0; i <= k; i++) {
        int rest = k - i;
        int j = n - 1 - rest;
        int bad = (m - 1) - k;
        int cur = INF;
        for (int t = 0; t <= bad; t++) {
            int other = bad - t;
            int ii = i + t;
            int jj = j - other;
            cur = min(cur, max(a[ii], a[jj]));
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}