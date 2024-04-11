#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

bitset<N> basis[N], mask[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
        for (auto &j : s) {
            j -= '0';
        }

        bitset<N> x, y;
        for (int j = 0; !s.empty(); ++j) {
            x[j] = s[0] % 2;

            int carry = 0;
            for (int k = s.size() - 1; k >= 0; --k) {
                int temp = carry;
                carry = s[k] % 2 == 1 ? 5 : 0;
                s[k] = s[k] / 2 + temp;
            }

            while (!s.empty() && s.back() == 0) {
                s.pop_back();
            }
        }

        bool ok = true;
        for (int j = 0; j < N && ok; ++j) {
            if (x[j]) {
                if (basis[j][j]) {
                    x ^= basis[j];
                    y ^= mask[j];
                } else {
                    basis[j] = x;
                    mask[j] = y;
                    mask[j][i] = true;
                    ok = false;
                }
            }
        }

        if (ok) {
            cout << y.count() << " ";
            for (int j = 0; j < N; ++j) {
                if (y[j]) {
                    cout << j << " ";
                }
            }
            cout << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}