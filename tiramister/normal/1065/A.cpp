#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        cout << (s / c) + (s / c / a * b) << endl;
    }
    return 0;
}