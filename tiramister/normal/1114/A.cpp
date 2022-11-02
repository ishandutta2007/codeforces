#include <iostream>

using namespace std;

int main() {
    int a[2][3];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) cin >> a[i][j];
        for (int j = 1; j < 3; ++j) a[i][j] += a[i][j - 1];
    }

    bool judge = true;
    for (int j = 0; j < 3; ++j) {
        if (a[0][j] > a[1][j]) judge = false;
    }
    cout << (judge ? "YES" : "NO") << endl;
    return 0;
}