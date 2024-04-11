#include <iostream>

using namespace std;

int main() {
    int x, y, x1, y1;
    cin >> x >> y;
    if (y == 0 || (y == 1 && x != 0) || y - 1 > x || (((x - (y - 1)) % 2) != 0)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}