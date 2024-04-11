#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i, --i;

        bool impossible = false;
        for (int i = 0; i < n; ++i) {
            impossible |= (a[i] % 2 != i % 2);
        }

        if (impossible) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> answer;
        auto op = [&](int p) {
            reverse(a.begin(), a.begin() + p);
            answer.push_back(p);
        };

        for (int i = n - 1; i > 0; i -= 2) {
            op(find(a.begin(), a.end(), i) - a.begin() + 1);
            int pair_pos = find(a.begin(), a.end(), i - 1) - a.begin();
            op(pair_pos);
            op(pair_pos + 2);
            op(3);
            op(i + 1);
        }

        cout << answer.size() << "\n";
        for (auto &i : answer) cout << i << " ";
        cout << "\n";
    }
}