#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    if (n & 1) {
        cout << (n - 3) / 2 + 1 << '\n';
        cout << 3 << ' ';
        n -= 3;
        while (n) cout << 2 << ' ', n -= 2;
    } else {
        cout << n / 2 << '\n';
        while (n) cout << 2 << ' ', n -= 2;
    }
}