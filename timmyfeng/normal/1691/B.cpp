#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            int size; cin >> size;
            groups[size].push_back(i);
        }

        bool solved = true;
        vector<int> answer(n);
        for (auto [size, indices] : groups) {
            solved &= indices.size() > 1;
            for (int i = 0; i < indices.size(); ++i) {
                answer[indices[i]] = indices[(i + 1) % indices.size()];
            }
        }

        if (!solved) {
            cout << -1 << "\n";
            continue;
        }

        for (auto i : answer) cout << i + 1 << " ";
        cout << "\n";
    }
}