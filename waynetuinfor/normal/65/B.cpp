#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int y[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> y[i];
    y[0] = 1000;
    for (int i = 1; i <= n; ++i) {
        int ty = y[i], ans = maxn;
        for (int j = 0, t = 1; j < 4; ++j, t *= 10) {
            int x = ty % 10;
            y[i] -= x * t;
            for (int d = 0; d < 10; ++d) {
                y[i] += d * t;
                if (y[i] >= y[i - 1]) ans = min(ans, y[i]);
                y[i] -= d * t;
            }
            y[i] += x * t;
            ty /= 10;
        }
        if (ans > 2011) {
            cout << "No solution" << endl;
            return 0;
        }
        y[i] = ans;
    }
    for (int i = 1; i <= n; ++i) cout << y[i] << endl;
}