#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 2) {
        if (a[0] == a[1]) cout << -1 << endl;
        else {
            cout << 1 << endl << 1 << endl;
        }
        return 0;
    }
    if (a[0] * 2 != s) {
        cout << 1 << endl << 1 << endl;
    } else {
        cout << 1 << endl << 2 << endl;
    }
    return 0;
}