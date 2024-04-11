#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 
int dist(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    pair<int, int> coo[3] = {a, b, c};
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        ret += abs(coo[i].first - coo[(i + 1) % 3].first) + abs(coo[i].second - coo[(i + 1) % 3].second);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;

    int x[n], y[n];
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    int lx = *min_element(x, x + n);
    int rx = *max_element(x, x + n);
    int ly = *min_element(y, y + n);
    int ry = *max_element(y, y + n);

    // x, y
    vector<pair<int, int>> corner;
    for (int i = 0; i < n; ++i) {
        if (x[i] == lx || x[i] == rx || y[i] == ly || y[i] == ry) {
            corner.push_back(make_pair(x[i], y[i]));
        }
    }
    int c = corner.size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < c; ++k) {
                ans = max(ans, dist(make_pair(x[i], y[i]), corner[j], corner[k]));
            }
        }
    }
    cout << ans << " ";

    for (int i = 4; i <= n; ++i) cout << ((rx - lx) + (ry - ly)) * 2 << " ";
    cout << endl;
    return 0;
}