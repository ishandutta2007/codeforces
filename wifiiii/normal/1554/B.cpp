#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll maxa = 2 * n, maxij = 1ll * n * (n - 1);
        ll ans = -1e18;
        for(int i = n; i >= 1; --i) {
            for(int j = i - 1; j >= 1; --j) {
                ans = max(ans, 1ll * i * j - 1ll * k * (a[i-1] | a[j-1]));
                if(ans >= 1ll * i * j) break;
            }
        }
        cout << ans << endl;
    }
}