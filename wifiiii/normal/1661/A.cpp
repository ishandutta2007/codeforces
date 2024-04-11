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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        ll ans = 0;
        for(int i = 1; i < n; ++i) {
            ans += min(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]),
                       abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
        }
        cout << ans << '\n';
    }
}