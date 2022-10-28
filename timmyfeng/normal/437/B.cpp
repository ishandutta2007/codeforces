#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum, limit;
    cin >> sum >> limit;

    vector<int> nums(limit);
    iota(nums.begin(), nums.end(), 1);
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return (a & -a) > (b & -b);
    });

    vector<int> ans;
    for (auto i : nums) {
        if ((i & -i) <= sum) {
            sum -= i & -i;
            ans.push_back(i);
        }
    }

    if (sum == 0) {
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}