#include <bits/stdc++.h>
using namespace std;

long long pre[1001][205], curr[1001][205];
long long MOD = 1e9 + 7;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    pre[0][0] = 1LL;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= k; j++) {
            for(int open = 0; open <= n; open++) {
                int d = 0;
                if (i < n - 1) d =  a[i + 1] - a[i];
                if (j >= open * d) {
                    curr[j][open] += pre[j - open * d][open] * (open + 1);
                }
                if (j >= (open + 1) * d)
                    curr[j][open] += pre[j - (open + 1) * d][open + 1] * (open + 1);
                if (open >= 1 && j >= (open - 1) * d)
                    curr[j][open] += pre[j - (open - 1) * d][open - 1];
                curr[j][open] %= MOD;
            }
        }
        for(int j = 0; j <= k; j++)
            for(int open = 0; open <= n; open++)
                pre[j][open] = curr[j][open], curr[j][open] = 0;
    }
    long long ans = 0LL;
    for(int j = 0; j <= k; j++)
        ans += pre[j][0], ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}