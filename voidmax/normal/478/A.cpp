#include <iostream>
#include <vector>
#define int long long

using namespace std;

int c1, c2, c3, c4, c5, n;

main() {
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    n = c1 + c2 + c3 + c4 + c5;
    if (n % 5 == 0 && n != 0) {
        cout << n / 5;
    }
    else {
        cout << -1;
    }
}