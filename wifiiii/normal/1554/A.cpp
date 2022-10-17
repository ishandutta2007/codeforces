#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll ans = 0;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 1; i < n; ++i) ans = max(ans, 1ll * a[i] * a[i-1]);
        cout << ans << endl;
    }
}