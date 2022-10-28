#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d\n", &t);

    while (t--) {
        int h, m, u, v;
        scanf("%d %d\n", &h, &m);
        scanf("%d:%d\n", &u, &v);

        while (true) {
            int x = u, y = v, xr = 0, yr = 0;
            bool ok = true;

            for (int i = 0; i < 2; ++i) {
                xr *= 10, yr *= 10;

                if (x % 10 == 0 || x % 10 == 1 || x % 10 == 8) {
                    yr += x % 10;
                } else if (x % 10 == 2 || x % 10 == 5) {
                    yr += 7 - x % 10;
                } else {
                    ok = false;
                }

                if (y % 10 == 0 || y % 10 == 1 || y % 10 == 8) {
                    xr += y % 10;
                } else if (y % 10 == 2 || y % 10 == 5) {
                    xr += 7 - y % 10;
                } else {
                    ok = false;
                }

                x /= 10, y /= 10;
            }

            if (ok && xr < h && yr < m) {
                break;
            }

            if (v == m - 1) {
                u = (u + 1) % h;
                v = 0;
            } else {
                ++v;
            }
        }

        printf("%02d:%02d\n", u, v);
    }
}