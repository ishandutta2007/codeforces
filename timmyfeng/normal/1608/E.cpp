#include <bits/stdc++.h>
using namespace std;

int get_bound(vector<pair<int, int>> &points, int target, int x_min, int y_min) {
    int index = 0;
    for (auto [x, y] : points) {
        if (x > x_min && y > y_min && ++index == target) {
            return x;
        }
    }
    return INT_MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> points(n);
    for (auto &[x, y, c] : points) {
        cin >> x >> y >> c, c--;
    }

    vector<pair<int, int>> points_by_x[4][3], points_by_y[4][3];
    for (int i = 0; i < 4; ++i) {
        for (auto [x, y, c] : points) {
            points_by_x[i][c].push_back({x, y});
            points_by_y[i][c].push_back({y, x});
        }

        for (int j = 0; j < 3; ++j) {
            sort(points_by_x[i][j].begin(), points_by_x[i][j].end());
            sort(points_by_y[i][j].begin(), points_by_y[i][j].end());
        }

        for (auto &[x, y, c] : points) {
            int x_new = y, y_new = -x;
            x = x_new, y = y_new;
        }
    }

    int low = 0, high = n / 3;
    while (low < high) {
        int mid = (low + high + 1) / 2;

        bool ok = false;
        vector<int> colors = {0, 1, 2};
        do {
            for (int z = 0; z < 4; ++z) {
                int y_min = get_bound(points_by_y[z][colors[0]], mid, INT_MIN, INT_MIN);
                int x_min = get_bound(points_by_x[z][colors[1]], mid, INT_MIN, y_min);
                ok |= (get_bound(points_by_x[z][colors[2]], mid, x_min, y_min) < INT_MAX);

                x_min = get_bound(points_by_x[z][colors[0]], mid, INT_MIN, INT_MIN);
                x_min = get_bound(points_by_x[z][colors[1]], mid, x_min, INT_MIN);
                ok |= (get_bound(points_by_x[z][colors[2]], mid, x_min, INT_MIN) < INT_MAX);
            }
        } while (next_permutation(colors.begin(), colors.end()));

        if (ok) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << high * 3 << "\n";
}