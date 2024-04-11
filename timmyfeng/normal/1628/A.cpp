#include <bits/stdc++.h>
using namespace std;

// if mex(A) > max(A), k = n
// otherwise Ans[1] = max(A)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        map<int, int> tally;
        for (auto i : a) tally[i]++;

        set<int> zeros;
        for (int i = 0; i <= n; ++i) {
            if (tally[i] == 0) zeros.insert(i);
        }

        vector<int> ans;

        int start = 0;
        while (start < n) {
            set<int> prefix;
            int prefix_mex = 0, end = start;
            do {
                prefix.insert(a[end++]);
                while (prefix.contains(prefix_mex)) ++prefix_mex;
            } while (*zeros.begin() != prefix_mex);

            ans.push_back(prefix_mex);

            while (start < end) {
                if (--tally[a[start]] == 0) zeros.insert(a[start]);
                ++start;
            }
        }

        cout << ans.size() << "\n";
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
}