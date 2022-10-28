#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    map<int, int> least;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j <= k; ++j) {
            if (least.count(a * j) == 0) {
                least[a * j] = j;
            } else {
                least[a * j] = min(least[a * j], j);
            }
        }
    }

    vector<pair<int, int>> sums(least.begin(), least.end());

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        int ans = k + 1;
        for (int i = 0, j = sums.size() - 1; i < j; ++i) {
            while (i < j && sums[i].first + sums[j].first > x) {
                --j;
            }
            if (i < j && sums[i].first + sums[j].first == x) {
                ans = min(ans, sums[i].second + sums[j].second);
            }
        }
        cout << (ans <= k ? ans : -1) << "\n";
    }
}