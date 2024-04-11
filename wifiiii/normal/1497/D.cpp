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
        vector<int> tag(n), a(n);
        for(int i = 0; i < n; ++i) cin >> tag[i];
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<ll> dp(n);
        for(int i = 1; i < n; ++i) {
            ll cur = 0;
            for(int j = i - 1; j >= 0; --j) {
                if(tag[i] != tag[j]) {
                    ll tmp = dp[j];
                    dp[j] = max(dp[j], cur + abs(a[i] - a[j]));
                    cur = max(cur, tmp + abs(a[i] - a[j]));
                }
            }
            dp[i] = cur;
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}