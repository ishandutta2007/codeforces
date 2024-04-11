#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        vector<int> partition, next(n);
        for (int i = 0; i < n; ++i) {
            next[i] = (i + 1) % n;
        }

        for (int i = 0; i < n; ++i) {
            if (__gcd(a[i], a[next[i]]) == 1) {
                partition.push_back(i);
            }
        }

        vector<int> ans;
        while (!partition.empty()) {
            vector<int> new_partition;
            for (auto i : partition) {
                if ((ans.empty() || ans.back() != i) && __gcd(a[i], a[next[i]]) == 1) {
                    ans.push_back(next[i]);
                    next[i] = next[next[i]];
                    new_partition.push_back(i);
                }
            }
            partition = new_partition;
        }

        cout << ans.size() << " ";
        for (auto i : ans) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
}