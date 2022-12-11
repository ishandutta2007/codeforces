#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1e5 + 7, M = 998244353;
int a[N];
int cnt[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[i] = 1;
    }
    long long sm = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int h = a[i];
        //cout << i << ' ' << a[i] << endl;
        for (int j = i - 1; j >= 0; j--) {
            //cout << i << ' ' << j << endl;
            int cur_h = (a[j] + cnt[j] - 1) / cnt[j];
            if (cur_h <= h)
                break;
            //cout << h << endl;
            int new_cnt = (a[j] + h - 1) / h;
            //cout << a[j] << ' ' << h << ' ' << new_cnt << endl;
            sm += 1ll * (new_cnt - cnt[j]) * (j + 1);
            sm %= M;
            cnt[j] = new_cnt;
            //cout << a[j] << ' ' << cnt[j] << endl;
            h = a[j] / cnt[j];
        }
        ans = (ans + sm) % M;
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("Desktop/input.tx", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}