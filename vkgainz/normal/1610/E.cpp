#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        set<pair<int, int>> in;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            in.insert({a[i], i});
        }
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                dp[i] = 1;
                continue;
            }
            if (i < n - 1 && a[i] == a[i + 1]) {
                dp[i] = 1 + dp[i + 1];
                continue;
            }
            dp[i] = 2;
            int st = i + 1;
            while (true) {
                int nxt = a[st] * 2 - a[i];
                auto get = in.lower_bound({nxt, -1});
                if (get == in.end()) {
                    break;
                } else {
                    ++dp[i];
                    st = get->second;
                }
            }
        }
        cout << n - *max_element(dp.begin(), dp.end()) << "\n";
    }
}