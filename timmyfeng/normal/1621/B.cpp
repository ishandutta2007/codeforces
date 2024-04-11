#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<pair<int, int>, int> segments;
        int left_index = INT_MAX, left_cost = INT_MAX;
        int right_index = INT_MIN, right_cost = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int l, r, c;
            cin >> l >> r >> c;

            if (l < left_index) left_index = l, left_cost = INT_MAX;
            if (r > right_index) right_index = r, right_cost = INT_MAX;

            if (l == left_index) left_cost = min(left_cost, c);
            if (r == right_index) right_cost = min(right_cost, c);

            if (!segments.contains({l, r})) segments[{l, r}] = INT_MAX;
            segments[{l, r}] = min(segments[{l, r}], c);

            cout << min(
                left_cost + right_cost,
                segments.contains({left_index, right_index}) ?
                    segments[{left_index, right_index}] :
                    INT_MAX
            ) << "\n";
        }
    }
}