#include <bits/stdc++.h>
#define int long long

using namespace std;

const int K = 6, N = 1e5 + 7, INF = 2e9;
int a[K];
int b[N];

int get_start_pos(int n, int mn, int struna) {
    int left = 0, right = n + 1, mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        if (b[mid] - a[struna] >= mn) right = mid;
        else left = mid;
    }
    return right;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    for (int i = 0; i < K; i++) cin >> a[i]; 
    sort(a, a + K);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(b + 1, b + n + 1);
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            int mn = b[i] - a[j];
            int mx = mn;
            int res[K];
            for (int jj = 0; jj < K; jj++) res[jj] = get_start_pos(n, mn, jj);
            if (res[0] != 1) continue;
            for (int jj = 0; jj < K - 1; jj++) {
                mx = max(mx, b[res[jj + 1] - 1] - a[jj]);
            }
            if (res[K - 1] != n + 1) mx = max(mx, b[n] - a[K - 1]);
            ans = min(ans, mx - mn);
        }
    }
    cout << ans << endl;
    return 0;
}