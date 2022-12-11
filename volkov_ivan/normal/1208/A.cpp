#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, n;
        cin >> a >> b >> n;
        n %= 3;
        if (n == 0) cout << a << endl;
        if (n == 1) cout << b << endl;
        if (n == 2) cout << (a ^ b) << endl;
    }
    return 0;
}