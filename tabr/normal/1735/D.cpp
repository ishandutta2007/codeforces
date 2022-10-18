#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            b[i] <<= 2;
            b[i] |= a[i][j];
        }
    }
    map<long long, int> mp;
    for (int i = 0; i < n; i++) {
        mp[b[i]] = i;
    }
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long c = 0;
            for (int l = 0; l < k; l++) {
                c <<= 2;
                if (a[i][l] == a[j][l]) {
                    c |= a[i][l];
                } else {
                    c |= a[i][l] ^ a[j][l] ^ 3;
                }
            }
            if (mp.count(c) && mp[c] > j) {
                d[i]++;
                d[j]++;
                d[mp[c]]++;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i] * (d[i] - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}