#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <numeric>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    vector<vector<int>> freq(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (char c : s[i]) {
            ++freq[i][c - 'a'];
        }
    }
    vector<long long> raw(1 << n, 1LL);
    long long MOD = 998244353;
    for (int i = 0; i < 26; i++) {
        vector<int> mn(1 << n);
        mn[0] = 1000000;
        for (int msk = 1; msk < (1 << n); msk++) {
            for (int j = 0; j < n; j++) {
                if (msk & (1 << j)) {
                    mn[msk] = min(mn[msk ^ (1 << j)]
                            , freq[j][i]);
                    break;
                }
            }
            raw[msk] *= (mn[msk] + 1);
            raw[msk] %= MOD;
        }
    }
    raw[0] = 0LL;
    vector<long long> ans(1 << n);
    for (int msk = 0; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) % 2) {
            ans[msk] = raw[msk];
        } else {
            ans[msk] = -raw[msk];
        }
    }
    for (int bit = 0; bit < n; bit++) {
        for (int msk = 0; msk < (1 << n); msk++) {
            if (msk & (1 << bit)) {
                ans[msk] += ans[msk ^ (1 << bit)];
                ans[msk] %= MOD;
            }
        }
    }
    ans[0] = 1;
    long long ret = 0LL;
    for (int msk = 0; msk < (1 << n); msk++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (msk & (1 << j)) {
                sum += j + 1;
            }
        }
        if (ans[msk] < 0) ans[msk] += MOD;
        sum *= __builtin_popcount(msk);
        ret ^= (ans[msk] * 1LL * sum);
    }
    cout << ret << "\n";
}