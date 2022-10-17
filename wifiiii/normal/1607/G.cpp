#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        ll sum = 0, sa = 0;
        for(int i = 0; i < n; ++i) cin >> a[i] >> b[i], sum += a[i] + b[i], sa += a[i];
        sum -= 1ll * n * m;
        ll goal = sa - sum / 2;
        ll sl = 0, sr = 0;
        for(int i = 0; i < n; ++i) {
            // a[i] <- a[i] - x
            // b[i] <- b[i] - (m - x)

            // 0 <= x <= m
            // a[i] - x >= 0 -> x <= a[i]
            // b[i] + x - m >= 0 -> x >= m - b[i]
            int l = max(0, m - b[i]), r = min(a[i], m);
            sl += l;
            sr += r;
        }
        if(sl <= goal && goal <= sr) {
            cout << abs(sum - 2 * (sa - goal)) << endl;
            ll res = goal - sl;
            for(int i = 0; i < n; ++i) {
                int l = max(0, m - b[i]), r = min(a[i], m);
                ll p = min<ll>(r - l, res);
                res -= p;
                cout << l + p << " " << m - (l + p) << endl;
            }
        } else if(goal < sl) {
            cout << abs(sum - 2 * (sa - sl)) << endl;
            for(int i = 0; i < n; ++i) {
                int l = max(0, m - b[i]), r = min(a[i], m);
                cout << l << " " << m - l << endl;
            }
        } else if(sr < goal) {
            cout << abs(sum - 2 * (sa - sr)) << endl;
            for(int i = 0; i < n; ++i) {
                int l = max(0, m - b[i]), r = min(a[i], m);
                cout << r << " " << m - r << endl;
            }
        }
    }
}