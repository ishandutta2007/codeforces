#include <bits/stdc++.h>

using namespace std;

int main() {
    array<pair<int, int>, 3> points;
    for (int i = 0; i < 3; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    array<int, 3> xs, ys;
    for (int i = 0; i < 3; ++i) {
        xs[i] = points[i].first;
        ys[i] = points[i].second;
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int cx = xs[1], cy = ys[1];

    vector<array<int, 4>> ans;
    for (int i = 0; i < 3; ++i) {
        int nx = points[i].first;
        int ny = points[i].second;

        if (cx != nx) {
            ans.push_back({ cx, cy, nx, cy });
        }
        if (cy != ny) {
            ans.push_back({ nx, cy, nx, ny });
        }
        
    }

    cout << ans.size() << '\n';
    for (auto &[a, b, c, d] : ans) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
    return 0;
}