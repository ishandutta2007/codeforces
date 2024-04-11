#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

multiset<int> teachers;
vector<int> updates[N];
int original[N];

void solve(int l, int r, bool has_violation) {
    assert(l <= r);
    if (l == r) {
        for (auto x : updates[l]) {
            cout << (!has_violation && x <= *teachers.rbegin() ? '1' : '0');
        }
    } else {
        int m = (l + r) / 2;

        vector<int> matched;
        bool has_new_violation = false;

        for (int i = m + 1; i <= r; ++i) {
            auto it = teachers.lower_bound(original[i]);
            if (it == teachers.end()) {
                has_new_violation = true;
            } else {
                matched.push_back(*it);
                teachers.erase(it);
            }
        }
        solve(l, m, has_violation || has_new_violation);
        teachers.insert(matched.begin(), matched.end());

        matched.clear();
        has_new_violation = false;

        for (int i = l; i <= m; ++i) {
            auto it = teachers.lower_bound(original[i]);
            if (it == teachers.end()) {
                has_new_violation = true;
            } else {
                matched.push_back(*it);
                teachers.erase(it);
            }
        }
        solve(m + 1, r, has_violation || has_new_violation);
        teachers.insert(matched.begin(), matched.end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        teachers.clear();
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;

            teachers.insert(a);
        }

        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;

            vector<int> group(k);
            for (auto &j : group) cin >> j;

            long long sum = accumulate(group.begin(), group.end(), 0LL);
            original[i] = (int) ((sum + k - 1) / k);

            updates[i].clear();
            for (int j = 0; j < k; ++j) {
                updates[i].push_back((int) ((sum - group[j] + k - 2) / (k - 1)));
            }
        }

        solve(0, m - 1, false);
        cout << "\n";
    }
}