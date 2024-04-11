/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

long long pref[301][301];
int num[301][301];
long long power[100301];
long long MOD = 1e9 + 37;
const int p = 53;
const int dollar = 29;
int dp[301][301];

int main()
{
    int n; cin >> n;
    vector<string> w(n);
    vector<long long> hsh(n);
    int totCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        long long curr = 1LL;
        for (char c : w[i]) {
            hsh[i] += (curr * 1LL * (c - 'a')) % MOD;
            curr *= p;
            curr %= MOD;
            hsh[i] %= MOD;
        }
        totCnt += w[i].size();
    }
    totCnt += n - 1;
    power[0] = 1LL;
    for (int i = 1; i <= 100300; i++) {
        power[i] = power[i - 1] * p % MOD;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (i == j) {
                pref[i][j] = hsh[j];
                cnt += w[i].size();
            } else {
                pref[i][j] = pref[i][j - 1];
                pref[i][j] += dollar * 1LL * power[cnt] % MOD;
                pref[i][j] %= MOD;
                pref[i][j] += hsh[j] * power[cnt + 1] % MOD;
                pref[i][j] %= MOD;
                cnt += w[j].size() + 1;
            }
            num[i][j] = cnt;
            if (pref[i][j] < 0) {
                pref[i][j] += MOD;
            }
        }
    }
    int ans = totCnt;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> dp(n + 1);
            for (int k = n - 1; k >= j + 1; k--) {
                int l = k + j - i;
                if (l >= n) continue;
                dp[k] = dp[k + 1];
                if (pref[i][j] == pref[k][l] && num[i][j] == num[k][l]) {
                    dp[k] = max(dp[k], 1 + dp[l + 1]);
                }
            }
            if (*max_element(dp.begin(), dp.end()) >= 1) {
                int save = (num[i][j] - (j - i + 1)) * (*max_element(dp.begin(), dp.end()) + 1);
                ans = min(ans, totCnt -save);
            }
        }
        
    }
    cout << ans << "\n";
}