#include <bits/stdc++.h>
using namespace std;

int k;

bool query(int a, int b, int c, int d, int e, int f) {
    if (a == 0 || b == 0) {
        return true;
    }

    if (k == 1) {
        swap(a, b), swap(c, d), swap(e, f);
    }

    cout << "? " << a << " " << b << " " << c << " "
        << d << " " << e << " " << f << endl;

    int r;
    cin >> r;

    return r == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = 1;

    for ( ; k < 2; ++k) {
        int x = n;
        vector<int> f;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                }
                f.push_back(i);
            }
        }
        if (x > 1) {
            f.push_back(x);
        }

        for (auto p : f) {
            int coeff = 1, gap = n / p;

            while (true) {
                int length = (p - (1 << __lg(p))) * gap;
                bool ok = query(length, m, 1, 1, n - length + 1, 1);

                for (int i = __lg(p) - 1; i >= 0; --i) {
                    length = (1 << i) * gap;
                    ok &= query(length, m, 1, 1, 1 + length, 1);
                }

                if (ok) ++coeff;
                else break;

                if (gap % p == 0) gap /= p;
                else break;
            }

            ans *= coeff;
        }

        swap(n, m);
    }

    cout << "! " << ans << endl;
}