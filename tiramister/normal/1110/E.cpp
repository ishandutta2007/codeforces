#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int c[2][n];
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) cin >> c[t][i];
    }

    // 
    if (c[0][0] != c[1][0] || c[0][n - 1] != c[1][n - 1]) {
        cout << "No" << endl;
        return 0;
    }

    int d[2][n - 1];  // 
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n - 1; ++i) d[t][i] = c[t][i + 1] - c[t][i];
        sort(d[t], d[t] + n - 1);
    }

    // 
    bool judge = true;
    for (int i = 0; i < n - 1; ++i) {
        if (d[0][i] != d[1][i]) judge = false;
    }

    cout << (judge ? "Yes" : "No") << endl;
    return 0;
}