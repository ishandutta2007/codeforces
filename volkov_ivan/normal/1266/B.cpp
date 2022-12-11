#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < 14) {
            cout << "NO" << endl;
            continue;
        }
        x %= 14;
        if (x >= 1 && x <= 6) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}