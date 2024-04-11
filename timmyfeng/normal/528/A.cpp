#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, n;
    cin >> w >> h >> n;

    multiset<int> row_lengths = {h}, col_lengths = {w};
    map<int, int> rows = {{0, h}}, cols = {{0, w}};

    while (n--) {
        char t;
        int x;
        cin >> t >> x;

        if (t == 'H') {
            auto it = --rows.upper_bound(x);

            row_lengths.erase(row_lengths.find(it->second - it->first));
            row_lengths.insert(it->second - x);
            row_lengths.insert(x - it->first);

            rows[x] = it->second;
            it->second = x;
        } else {
            auto it = --cols.upper_bound(x);

            col_lengths.erase(col_lengths.find(it->second - it->first));
            col_lengths.insert(it->second - x);
            col_lengths.insert(x - it->first);

            cols[x] = it->second;
            it->second = x;
        }

        cout << (long long) *--row_lengths.end() * *--col_lengths.end() << "\n";
    }
}