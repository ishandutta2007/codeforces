#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll s = 0;
        map<ll, int> mp;
        for(int i = 0; i < n; ++i) {
            s += a[i];
            mp[s] = i;
        }
        int ans = 0;
        ll b = 0;
        for(int i = n - 1; i >= 0; --i) {
            b += a[i];
            if(mp.count(b)) {
                int pos = mp[b];
                if(pos < i) {
                    ans = max(ans, pos + 1 + n - i);
                }
            }
        }
        cout << ans << '\n';
    }
}