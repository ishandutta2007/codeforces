#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int d = n; d > 0; d--) {
            int p = d / __gcd(d, k);
            int all = 0;
            for (int i = 0; i < 26; i++) {
                all += cnt[i] / p;
            }
            if (all >= __gcd(d, k)) {
                cout << d << '\n';
                break;
            }
        }
    }
    return 0;
}