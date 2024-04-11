#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), cnt(2 * n + 1);
        map<int, int> mp;
        int tp = n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] >= n && !mp.count(a[i])) mp[a[i]] = tp++;
            if(a[i] >= n) cnt[mp[a[i]]]++;
            else cnt[a[i]]++;
        }
        vector<int> b;
        for(int i = 0; i <= 2 * n; ++i) if(cnt[i]) b.push_back(cnt[i]);
        sort(b.begin(), b.end());
        vector<int> cnt2(2 * n + 1);
        for(int i : b) cnt2[i] += 1; for(int i = 1; i <= 2 * n; ++i) cnt2[i] += cnt2[i - 1];
        int x = 0, y = 0, r = b.size(), sum = 0, ans = 1e9;
        for(int m = 0; m <= n; ++m) {
            if(x > k) break;
            while(y < b.size() && sum + b[y] <= k) {
                sum += b[y];
                if(b[y]) --r;
                ++y;
            }
            ans = min(ans, r);
            if(!cnt[m]) ++x;
            else {
                int p = --cnt2[cnt[m]];
                if(p < y) sum -= b[p];
                else --r;
                b[p] = 0;
            }
        }
        cout << ans << '\n';
    }
}