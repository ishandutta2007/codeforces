#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        vector<int> cnt(k);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            for(int j = 0; j < k; ++j) {
                if(x >> j & 1) cnt[j] += 1;
            }
        }
        for(int i = 0; i < k; ++i) {
            if(cnt[i] >= n - cnt[i]) ans |= 1 << i;
        }
        cout << ans << '\n';
    }
}