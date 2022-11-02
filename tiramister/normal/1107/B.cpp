#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        ll k, x;
        cin >> k >> x;
        cout << 9 * (k - 1) + x << endl;
    }
    return 0;
}