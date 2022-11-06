#include <iostream>
#include <vector>
#include <cmath>
#define int long long

using namespace std;

int a, b;

main() {
    cin >> a >> b;
    if (a % 2) {
        a++;
    }
    if (a + 2 > b) {
        cout << -1;
    }
    else {
        cout << a << ' ' << a + 1 << ' ' << a + 2;
    }
}