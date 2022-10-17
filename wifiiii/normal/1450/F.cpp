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
        vector<int> a(n), cnt(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i], cnt[a[i]]++;
        if(n < 2 * *max_element(cnt.begin(), cnt.end()) - 1) {
            cout << -1 << endl;
            continue;
        }
        int ans = -1, tot = 0;
        vector<int> cnt2(n);
        for(int i = 0, j = 0; i < n; ++i) {
            if(i + 1 == n || a[i] == a[i + 1]) {
                cnt2[a[i]] += 1;
                cnt2[a[j]] += 1;
                tot += 2;
                j = i + 1;
                ans += 1;
            }
        }
        ans += max(0, (2 * *max_element(cnt2.begin(), cnt2.end()) - 1 - tot) / 2);
        cout << ans << '\n';
    }
}