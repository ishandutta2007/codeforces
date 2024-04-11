#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    vector<int> a;
    while (t--) {
        int x;
        cin >> x >> s;
        a.resize(x);
        int sz = s.size();
        for (int i = 0; i < sz && i < x; ++i) {
            a[i] = s[i] - '0';
        }
        long long sol = s.size();
        for (int i = 1; i <= x; ++i) {
            int r = sz;
            for (int j = 1; j < a[i - 1] && sz < x; ++j) {
                for (int k = i; k < r && sz < x; ++k) {
                    a[sz] = a[k];
                    ++sz;
                }
            }
            sol = ((sol - i + MOD) % MOD * a[i - 1] + i) % MOD;
        }
        cout << sol << '\n';
    }
}