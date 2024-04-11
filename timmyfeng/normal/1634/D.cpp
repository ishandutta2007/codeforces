#include <bits/stdc++.h>
using namespace std;

int query(vector<int> q) {
    cout << "? ";
    for (auto i : q) cout << i << " ";
    cout << endl;

    int result; cin >> result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> candidates(n);
        iota(begin(candidates), end(candidates), 1);

        while (ssize(candidates) > 2) {
            vector<int> diff(4);
            for (int i = 0; i < 4; ++i) {
                vector<int> indices;
                for (int j = 0; j < 4; ++j) if (i != j) indices.push_back(candidates[j]);
                diff[i] = query(indices);
            }

            vector<int> order = {0, 1, 2, 3};
            ranges::sort(order, [&](int i, int j) { return diff[i] < diff[j]; });

            vector<int> not_zero = {candidates[order[2]], candidates[order[3]]};
            for (auto i : not_zero) {
                candidates.erase(ranges::find(candidates, i));
            }

            if (ssize(candidates) == 3) candidates.push_back(not_zero[0]);
        }

        cout << "! " << candidates[0] << " " << candidates[1] << endl;
    }
}