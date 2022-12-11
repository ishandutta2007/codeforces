#include <iostream>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (r == 1) {
        for (int i = 0; i < c; i++) cout << i + 2 << ' ';
        cout << endl;
        return 0;
    }
    if (c == 1) {
        for (int i = 0; i < r; i++) {
            cout << i + 2 << endl;
        }
        return 0;
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int cur = (r + j) * i;
            cout << cur << ' ';
        }
        cout << endl;
    }
    return 0;
}