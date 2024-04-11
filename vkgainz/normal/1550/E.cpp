#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int lo = 0, hi = n;
    for(int r = 0; r < 25; r++) {
        int mid = (lo + hi + 1) / 2;
        vector<vector<int>> lst(n, vector<int>(k, n + 1));
        for(int j = 0; j < k; j++) {
            vector<int> tmp(n);
            for(int i = 0; i < n; i++) {
                tmp[i] = (s[i] == '?' || s[i] - 'a' == j) ? 1 : -1;
            }
            int sumLastK = 0;
            for(int i = 0; i < n; i++) {
                sumLastK += tmp[i];
                if(i >= mid) sumLastK -= tmp[i - mid];
                if(sumLastK == mid) {
                    lst[i][j] = i - mid + 1;
                }
                else if(i > 0) {
                    lst[i][j] = lst[i - 1][j];
                }
            }
        }
        vector<int> dp(1 << k, -1);
        dp[0] = n;
        for(int msk = 0; msk < 1 << k; msk++) {
            for(int out = 0; out < k; out++) {
                if((msk & (1 << out)) == 0) continue;
                int x = dp[msk ^ (1 << out)];
                int st = x - 1;
                if(st < 0 || lst[st][out] > n) continue;
                dp[msk] = max(dp[msk], lst[st][out]);
            }
        }
        //cout << mid << " " << dp[(1 << k) - 1] << "\n";
        if(dp[(1 << k) - 1] >= 0) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
}