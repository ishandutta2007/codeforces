#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string ans(n, '0');
        vector<int> a(n), cnt(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i], cnt[a[i]] += 1;
        int cur = 0, i = 0, j = n - 1;
        while(cur < n) {
            if(a[i] == cur) {
                ++i;
                ++cur;
            } else if(a[j] == cur) {
                --j;
                ++cur;
            } else {
                int mn = a[i];
                for(int k = i; k <= j; ++k) {
                    mn = min(mn, a[k]);
                }
                if(mn == cur) {
                    ans[n - cur - 1] = '1';
                }
                break;
            }
            ans[n - cur] = '1';
            if(cnt[cur - 1] > 1) break;
        }
        sort(a.begin(), a.end());
        int ok = 1;
        for(int i = 0; i < n; ++i) if(a[i] != i) ok = 0;
        if(ok) ans[0] = '1';
        cout << ans << '\n';
    }
}