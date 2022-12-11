#include <iostream>

using namespace std;

int main() {
    int res = 0;
    cout << "? ";
    for (int i = 0; i < 100; i++) {
        cout << i << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    res += (x >> 7) << 7;
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << (i << 7) << ' ';
    }
    cout << endl;
    cin >> x;
    res += x & 127;
    cout << "! " << res << endl;
    return 0;
}