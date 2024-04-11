#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (c - a) * (d - b) + 1 << '\n';
    }
}