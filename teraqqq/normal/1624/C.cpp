#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), cnt(n+1);
        for (int& x : a) cin >> x;

        bool ok = true;
        for (int& x : a) {
            while (x > n || cnt[x] == 1) x /= 2;

            cnt[x]++;
            if (x == 0) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}