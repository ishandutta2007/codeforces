#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    ll dp[N + 1];
    fill(dp + 1, dp + N + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        // dp[n] = a[1]~a[i]ngood subseqs

        int a;
        cin >> a;

        vector<int> facts;
        for (int n = 1; n <= N && n * n <= a; ++n) {
            if (a % n == 0) {
                facts.push_back(n);
                if (a / n <= N && a / n != n) facts.push_back(a / n);
            }
        }

        sort(facts.rbegin(), facts.rend());

        for (int j : facts) {
            dp[j] += dp[j - 1];
            dp[j] %= MOD;
        }
    }

    cout << accumulate(dp + 1, dp + N + 1, 0LL) % MOD << endl;
    return 0;
}