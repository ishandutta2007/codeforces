#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, sq = 320;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<int, int> prv;
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        assert(y <= i - 1);
        int c = 0;
        for (int j = 1; j <= sqrt(x); ++j) if (x % j == 0) {
            if (prv[j] < i - y) ++c;
            prv[j] = i;
            if (j * j == x) break;
            if (prv[x / j] < i - y) ++c;
            prv[x / j] = i;
        }
        cout << c << endl;
    }
    return 0;
}