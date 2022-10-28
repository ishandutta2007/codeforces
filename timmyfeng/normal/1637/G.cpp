#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }

        vector<pair<int, int>> ans;
        multiset<int, greater<int>> nums;
        for (int i = 1; i <= n; ++i) nums.insert(i);

        int bit = 1;
        map<int, int> powers;
        for ( ; bit < 2 * n; bit *= 2) {
            vector<int> new_nums;

            auto it = nums.begin();
            while (it != nums.end()) {
                if (*it == bit) {
                    ++powers[*it];
                    nums.erase(it++);
                } else if (*it / bit % 2 == 1) {
                    int other = bit_ceil((unsigned) *it) - *it;
                    assert(nums.contains(other));

                    ans.push_back({other, *it});

                    new_nums.push_back(*it - other);
                    new_nums.push_back(*it + other);

                    nums.erase(nums.find(other));
                    nums.erase(it++);
                } else ++it;
            }

            nums.insert(begin(new_nums), end(new_nums));
        }
        bit /= 2;

        int dupe = (n == 5) ? 2 : bit / 2;
        powers[dupe] -= 2;
        ++powers[2 * dupe];
        ans.push_back({dupe, dupe});

        for (auto &[p, c] : powers) {
            if (p < bit) {
                for (int i = 0; i < c; ++i) {
                    ans.push_back({0, p});
                    ans.push_back({p, p});
                }
                powers[2 * p] += c;
                c = 0;
            }
        }

        ans.push_back({0, bit});

        cout << ans.size() << "\n";
        for (auto [x, y] : ans) cout << x << " " << y << "\n";
    }
}