#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

vector<bitset<N>> stk;
bitset<N> ans;

void solve(int l, int r, vector<array<int, 3>> &queries) {
    vector<array<int, 3>> left, right;
    int m = (l + r) / 2, undo = 0;

    for (auto [a, b, x] : queries) {
        if (a <= l && r <= b) {
            stk.push_back(stk.back() | (stk.back() << x));
            ++undo;
        } else {
            if (a <= m) {
                left.push_back({a, b, x});
            }
            if (b > m) {
                right.push_back({a, b, x});
            }
        }
    }

    if (l == r) {
        ans |= stk.back();
    } else {
        solve(l, m, left);
        solve(m + 1, r, right);
    }

    while (undo--) {
        stk.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> queries(q);
    for (auto &[l, r, x] : queries) {
        cin >> l >> r >> x;
    }

    stk.emplace_back();
    stk.back()[0] = true;

    solve(1, n, queries);

    vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) {
            nums.push_back(i);
        }
    }

    cout << nums.size() << "\n";
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << "\n";
}