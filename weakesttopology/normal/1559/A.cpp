#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ans = i ? ans & a : a;
        }
        cout << ans << '\n';
    }
    exit(0);
}