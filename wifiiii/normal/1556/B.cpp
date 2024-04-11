#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(2);
        vector<vector<int>> pos(2);
        for(int i = 0; i < n; ++i) cin >> a[i], a[i] %= 2, cnt[a[i]]++, pos[a[i]].push_back(i);
        if(abs(cnt[0] - cnt[1]) > 1) {
            cout << -1 << endl;
        } else {
            ll ans = 1e18;
            if(cnt[1] >= cnt[0]) {
                // 1 0 1 0 ...
                ll p = 0, tmp = 0;
                for(int i : pos[1]) {
                    tmp += abs(i - p);
                    p += 2;
                }
                p = 1;
                for(int i : pos[0]) {
                    tmp += abs(i - p);
                    p += 2;
                }
                ans = min(ans, tmp);
            }
            if(cnt[0] >= cnt[1]) {
                // 0 1 0 1 ...
                ll p = 0, tmp = 0;
                for(int i : pos[0]) {
                    tmp += abs(i - p);
                    p += 2;
                }
                p = 1;
                for(int i : pos[1]) {
                    tmp += abs(i - p);
                    p += 2;
                }
                ans = min(ans, tmp);
            }
            cout << ans / 2 << endl;
        }
    }
}