#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        cout << r / 2 << " " << r - r % 2 << endl;
    }
    return 0;
}