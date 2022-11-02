#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int r[n + 1];
    r[n] = 1e9;  // 110^9
    for (int i = 0; i < n; ++i) cin >> r[i];
    sort(r, r + n + 1);

    vector<int> h;
    for (int i = 0; i < m; ++i) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 > 1) continue;
        h.push_back(x2);
    }
    sort(h.begin(), h.end());
    m = h.size();  // m

    int ans = n + m;
    for (int i = 0; i <= n; ++i) {
        int rim = h.end() - lower_bound(h.begin(), h.end(), r[i]);  // hr[i]
        ans = min(ans, i + rim);
    }

    cout << ans << endl;
    return 0;
}