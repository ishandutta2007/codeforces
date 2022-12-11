#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7, K = 61, M = 1e9 + 7;
int cnt[K];
int val_one[K];
int a[N];

void solve() {
    int ans = 0;
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < K; j++)
            if (a[i] & (1ll << j))
                cnt[j]++;
    }
    for (int i = 1; i <= n; i++) {
        int sm_left = 0;
        int sm_right = 0;
        for (int j = 0; j < K; j++) {
            int cnt_left = cnt[j], cnt_right = cnt[j];
            bool has = 0;
            if (a[i] & (1ll << j))
                has = 1;
            if (has)
                cnt_right = n;
            else
                cnt_left = 0;
            sm_left = (sm_left + cnt_left * val_one[j]) % M;
            sm_right = (sm_right + cnt_right * val_one[j]) % M;
        }
        ans = (ans + sm_left * sm_right) % M;
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < K; i++)
        val_one[i] = (1ll << i) % M;
    for (int i = 0; i < t; i++)
        solve();
}