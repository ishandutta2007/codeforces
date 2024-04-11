#include <iostream>

using namespace std;

int calc(int l, int v) {
    return l / v;
}

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, v, l, r;
        cin >> L >> v >> l >> r;
        cout << calc(L, v) - calc(r, v) + calc(l - 1, v) << endl;
    }
    return 0;
}