#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 5000;

int main() {
    int n;
    cin >> n;
    int a[n], b[MAX_N + 1], cnt[MAX_N + 1], dp[MAX_N + 1], now_cnt[MAX_N + 1];
    vector <pair <int, int> > add[MAX_N + 1];
    for (int i = 0; i <= MAX_N; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int now, bal;
    for (int i = 0; i < n; i++) {
        now = bal = 0;
        for (int j = 0; j <= MAX_N; j++) now_cnt[j] = 0;
        for (int j = i; j < n; j++) {
            if (now_cnt[a[j]] == 0) {
                bal++;
                now ^= a[j];
            }
            now_cnt[a[j]]++;
            if (now_cnt[a[j]] == cnt[a[j]]) bal--;
            if (bal == 0) add[j].push_back(make_pair(i, now));
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (pair <int, int> elem : add[i - 1]) {
            dp[i] = max(dp[i], dp[elem.first] + elem.second);
        }
    }
    cout << dp[n] << endl;
    return 0;
}