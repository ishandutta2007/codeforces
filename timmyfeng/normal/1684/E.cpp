#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        sort(a.begin(), a.end());

        int moves = 0, threshold = 0;
        while (true) {
            auto it = lower_bound(a.begin(), a.end(), threshold);
            if (it == a.end() || *it != threshold) {
                if (moves == k || a[n - 1 - moves] < threshold) break;
                ++moves;
            }
            ++threshold;
        }

        vector<int> freq;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[i] == a[j]) ++j;
            if (a[i] > threshold) freq.push_back(j - i);
        }
        sort(freq.begin(), freq.end());

        int answer = (int) freq.size();
        for (int i = 0; i < (int) freq.size(); ++i) {
            if (freq[i] <= k) k -= freq[i], --answer;
        }

        cout << answer << "\n";
    }
}