#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void fail() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> swapped(n, false);
    vector<int> f(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (min(x, y) >= n || max(x, y) < n) fail();
        if (x > y) {
            swap(x, y);
            swapped[x] = true;
        }
        f[x] = y;
    }

    vector<int> suff_max(n + 1, -INF);

    for (int i = n - 1; i >= 0; --i) {
        suff_max[i] = max(suff_max[i + 1], f[i]);
    }

    int flips[2]{}, sz[2]{}, last[2] = { +INF, +INF };
    int res = 0;

    for (int i = 0; i < n; ++i) {
        bool good = false;
        for (int t = 0; t < 2; ++t) {
            if (last[t] > f[i]) {
                last[t] = f[i], sz[t] += 1, flips[t] += swapped[i];
                good = true;
                break;
            }
        }
        if (not good) fail();
        if (suff_max[i + 1] < *min_element(all(last))) {
            int x = +INF;
            for (int t = 0; t < 2; ++t) {
                x = min(x, flips[t] + sz[t ^ 1] - flips[t ^ 1]);
            }
            res += x;
            fill(all(flips), 0), fill(all(sz), 0), fill(all(last), +INF);
        }
    }

    cout << res << endl;

    exit(0);
}