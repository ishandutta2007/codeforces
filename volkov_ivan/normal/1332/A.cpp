#include <iostream>

using namespace std;

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c, d, x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int fx = x + b - a;
        int fy = y + d - c;
        if (x1 <= fx && fx <= x2 && y1 <= fy && fy <= y2 && x1 <= x && x <= x2 && y1 <= y && y <= y2) {
            if (a == b && a != 0 && x == x1 && x == x2) {
                cout << "NO\n";
                continue;
            }
            if (c == d && c != 0 && y == y1 && y == y2) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}