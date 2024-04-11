#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(31);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            for(int j = 0; j <= 30; ++j) {
                if(x >> j & 1) cnt[j]++;
            }
        }
        int ans = 0;
        for(int i = 30; i >= 0; --i) {
            if(k >= n - cnt[i]) {
                k -= n - cnt[i];
                ans |= 1 << i;
            }
        }
        cout << ans << '\n';
    }
}