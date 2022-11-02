#include <iostream>

using namespace std;

int calc(int x) {
    return x % 2 == 0 ? x / 2 : x / 2 - x;
}

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}