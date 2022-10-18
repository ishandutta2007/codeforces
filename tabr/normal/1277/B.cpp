#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> mp;
        rep(i, 0, n) {
            cin >> a[i];
            b[i] = a[i];
            int c = 0;
            while (b[i] % 2 == 0) {
                b[i] /= 2;
                c++;
            }
            mp[b[i]] = max(mp[b[i]], c);
        }
        ll ans = 0;
        for (auto x : mp)
            ans += x.second;
        cout << ans << endl;
    }
    return 0;
}