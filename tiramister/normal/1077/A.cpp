#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        ll a, b, k;
        cin >> a >> b >> k;
        cout << (a - b) * (k / 2) + a * (k % 2) << endl;
    }
    return 0;
}