#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int x[n + m], t[n + m];
    for (int i = 0; i < n + m; ++i) cin >> x[i];
    for (int i = 0; i < n + m; ++i) cin >> t[i];

    vector<int> taxi;
    for (int i = 0; i < n + m; ++i) {
        if (t[i] == 1) taxi.push_back(i);
    }

    int ans[taxi.size()];
    fill(ans, ans + taxi.size(), 0);

    for (int i = 0; i < n + m; ++i) {
        if (t[i] == 1) continue;

        // x[taxi[ok]] < x[i]
        int ok = -1, ng = taxi.size();
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (x[taxi[mid]] < x[i]) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        if (ok < 0) {
            ++ans[ok + 1];
        } else if (ok == taxi.size() - 1) {
            ++ans[ok];
        } else {
            ++ans[abs(x[taxi[ok]] - x[i]) <= abs(x[taxi[ok + 1]] - x[i]) ? ok : ok + 1];
        }
    }

    for (int i = 0; i < taxi.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}