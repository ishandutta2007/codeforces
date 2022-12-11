#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r;
    cin >> n;
    int a[n], f[n][n], maximum[n][n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[0][i] = a[i];
        maximum[0][i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            f[i][j] = f[i - 1][j] ^ f[i - 1][j + 1];
            maximum[i][j] = max(max(maximum[i - 1][j], maximum[i - 1][j + 1]), f[i][j]);
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << maximum[r - l][l - 1] << '\n';
    }
    return 0;
}