#include <bits/stdc++.h>
using namespace std;

const int L = 60;

long long offset[L];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 3) {
            long long x;
            cin >> x;

            int i = __lg(x);
            x += offset[i];
            if (__lg(x) > i) {
                x -= 1LL << i;
            }

            while (i >= 0) {
                long long y = x - offset[i];
                while (__lg(y) < i) {
                    y += 1LL << i;
                }
                cout << y << " ";
                x /= 2;
                --i;
            }
            cout << "\n";
        } else if (t == 2) {
            long long x, k;
            cin >> x >> k;

            for (int i = __lg(x); i < L; ++i) {
                k %= 1LL << i;
                offset[i] += k;
                offset[i] %= 1LL << i;
                if (offset[i] < 0) {
                    offset[i] += 1LL << i;
                }
                k *= 2;
            }
        } else {
            long long x, k;
            cin >> x >> k;
            int i = __lg(x);

            k %= 1LL << i;
            offset[i] += k;
            offset[i] %= 1LL << i;
            if (offset[i] < 0) {
                offset[i] += 1LL << i;
            }
        }
    }
}