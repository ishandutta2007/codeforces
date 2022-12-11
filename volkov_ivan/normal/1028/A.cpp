#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bool fnd = 0;
    int fi, fj, len;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B' && !fnd) {
                fnd = 1;
                int j2 = j;
                for (j2; j2 < m; j2++) {
                    if (a[i][j2] == 'W') break;
                }
                j2--;
                len = j2 - j + 1;
                fi = i;
                fj = j;
                break;
            }
        }
        if (fnd) break;
    }
    int ci = fi + len / 2, cj = fj + len / 2;
    cout << ci + 1 << ' ' << cj + 1 << endl;
    return 0;
}