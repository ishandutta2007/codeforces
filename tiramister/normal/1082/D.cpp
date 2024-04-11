#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0, a[N + 1];

    for (int v = 1; v <= N; ++v) {
        cin >> a[v];
        sum += a[v];
    }

    if (sum < 2 * N - 2) {
        cout << "NO" << endl;
        return 0;
    }

    vector<pair<int, int>> deg;
    vector<pair<int, int>> path;
    int cur = -1;

    for (int v = 1; v <= N; ++v) {
        if (a[v] == 1) continue;

        if (!deg.empty()) {
            path.push_back(make_pair(cur, v));
            --deg.back().second;
        }

        deg.push_back(make_pair(v, a[v] - 1));
        cur = v;
    }

    int ans = path.size();

    int f = deg.front().first;
    deg.push_back(make_pair(f, 1));

    int leaf = 0;
    for (int v = 1; v <= N; ++v) {
        if (a[v] > 1) continue;
        ++leaf;
        while (deg.back().second == 0) {
            deg.pop_back();
        }

        path.push_back(make_pair(v, deg.back().first));
        --deg.back().second;
    }

    cout << "YES " << ans + min(leaf, 2) << endl;
    cout << path.size() << endl;
    for (auto p : path) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}