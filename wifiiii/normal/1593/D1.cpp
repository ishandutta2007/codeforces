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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        if(a[0] == a.back()) {
            cout << -1 << '\n';
            continue;
        }
        for(int i = 1; i < n; ++i) a[i] -= a[0]; a[0] = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i) ans = gcd(ans, a[i]);
        cout << ans << '\n';
    }
}