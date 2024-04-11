#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] + a[i] >= l && a[i] + a[i] <= r) --ans;
            ans += upper_bound(a.begin(), a.end(), r - a[i])
                    - lower_bound(a.begin(), a.end(), l - a[i]);
        }
        cout << ans / 2 << '\n';
    }
}