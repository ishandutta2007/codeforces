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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (s[i] - '0');
    }
    const int t = 250;
    ll ans = 0;
    for (int i = 1; i < t; i++) {
        unordered_map<int, int> mp;
        mp[-1]++;
        for (int j = 0; j < n; j++) {
            ans += mp[j - i * p[j + 1]]++;
        }
    }
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            a.emplace_back(i);
        }
    }
    int c = a.size();
    for (int i = 0; i < c; i++) {
        int l = a[i] - (i ? a[i - 1] + 1 : 0);
        for (int j = i; j < c; j++) {
            int r = (j != c - 1 ? a[j + 1] : n) - a[j] - 1;
            int s = a[j] - a[i] + 1;
            int cnt = j - i + 1;
            if (cnt * t > n) {
                break;
            }
            for (int k = t; k <= n; k++) {
                int x = cnt * k;
                if (x > l + r + s) {
                    break;
                }
                if (x < s) {
                    continue;
                }
                ans += max(0, min(l + s + r - x, l) + 1 - max(0, l + s - x));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}