#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<int> next_less(n, n), next_greater(n, n);

        vector<pair<int, int>> mono = {{0, -1}};
        for (int i = 0; i < n; ++i) {
            while (mono.back().first > a[i]) {
                auto [aj, j] = mono.back();
                mono.pop_back();
                next_less[j] = i;
            }
            mono.push_back({a[i], i});
        }

        mono = {{n + 1, -1}};
        for (int i = 0; i < n; ++i) {
            while (mono.back().first < a[i]) {
                auto [aj, j] = mono.back();
                mono.pop_back();
                next_greater[j] = i;
            }
            mono.push_back({a[i], i});
        }

        int answer = 0;
        for (int i = 0; i < n - 1; ) {
            int j = i;
            while (next_less[j] < next_greater[i]) j = next_less[j];
            while (next_greater[j] < next_less[i]) j = next_greater[j];
            i = j, ++answer;
        }

        cout << answer << "\n";
    }
}