#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map <int, int> dict;
    int prev[n + 1];
    int dp[n + 1];
    dp[0] = 0;
    int maxi = -1, last;
    for (int i = 1; i <= n; i++) {
        if (dict.find(a[i] - 1) == dict.end()) dp[i] = 1;
        else dp[i] = dp[dict[a[i] - 1]] + 1;
        prev[i] = dict[a[i] - 1];
        dict[a[i]] = i;
        if (dp[i] > maxi) {
            maxi = dp[i];
            last = i;
        }
    }
    vector <int> ans;
    int now = last;
    while (now != 0) {
        ans.push_back(now);
        now = prev[now];
    }
    cout << dp[last] << endl;
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}