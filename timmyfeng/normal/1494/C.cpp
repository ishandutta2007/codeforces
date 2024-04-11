#include <bits/stdc++.h>
using namespace std;

array<vector<int>, 2> read(int n) {
    vector<int> neg, pos;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a < 0) {
            neg.push_back(-a);
        } else {
            pos.push_back(a);
        }
    }
    reverse(neg.begin(), neg.end());
    return {neg, pos};
}

int solve(vector<int> a, vector<int> b) {
    vector<int> suffix(b.size() + 1);
    for (int i = b.size() - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + binary_search(a.begin(), a.end(), b[i]);
    }

    for (int i = 0; i < (int) a.size(); ++i) {
        a[i] -= i;
    }

    int ans = suffix[0];
    for (int i = 0; i < (int) b.size(); ++i) {
        int k = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        int j = lower_bound(b.begin(), b.end(), b[i] + k) - b.begin();
        ans = max(ans, j - i + suffix[j]); 
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        auto [a_neg, a_pos] = read(n);
        auto [b_neg, b_pos] = read(m);

        cout << solve(a_neg, b_neg) + solve(a_pos, b_pos) << "\n";
    }
}