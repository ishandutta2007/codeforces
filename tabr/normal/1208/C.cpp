#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int k = 1;
    int m = 2 * n;

    rep(i, 0, n) rep(j, 0, n) {
        if (j == 0) {
            k = (i % (n / 2)) * m + 1;
            if (2 * i >= n)
                k += 2;
        }
        if (2 * j == n) {
            k = (i % (n / 2)) * m;
            if (2 * i < n)
                k += 2;
        }
        cout << k << ' ';
        k += 4;
        if (j == n - 1)
            cout << endl;
    }

    return 0;
}