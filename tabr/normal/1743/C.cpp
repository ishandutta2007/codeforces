#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using ll = long long;

template<class T>
using vec = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vec<int> a(n);
        rep(i, n) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            if (s[i] == '0') {
                j++;
                continue;
            }
            int mn = 1e9;
            while (j < n && s[j] == '1') {
                mn = min(mn, a[j]);
                ans += a[j];
                j++;
            }
            if (i != 0 && a[i - 1] > mn) {
                ans += a[i - 1] - mn;
            }
        }
        cout << ans << endl;
    }
    return 0;
}