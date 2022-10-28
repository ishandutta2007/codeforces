#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;

int solve(vector<int> &a, int b) {
    if (b < 0) return 0;
    vector<int> on, off;
    for (auto i : a) {
        if (i & (1 << b)) on.push_back(i);
        else off.push_back(i);
    }
    if (on.empty()) return solve(off, b - 1);
    if (off.empty()) return solve(on, b - 1);
    return min(solve(on, b - 1), solve(off, b - 1)) + (1 << b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    nums.resize(n);
    for (auto &i : nums)
        cin >> i;
    cout << solve(nums, 30) << "\n";
}