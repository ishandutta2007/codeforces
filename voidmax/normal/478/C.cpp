#include <iostream>
#include <vector>
#define int long long

using namespace std;

int a, b, c, L, R;

bool check(int z) {
    if (z * 3 <= a + b + c) {
         if (!(a + b < z || a + c < z || b + c < z)) {
            return true;
         }
    }
    return false;
}

main() {
    cin >> a >> b >> c;
    R = max(a, max(b, c)) + 1;
    L = 0;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (!check(M)) {
            R = M;
        }
        else {
            L = M;
        }
    }
    cout << L;
}