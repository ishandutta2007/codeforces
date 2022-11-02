#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int l, r, d;
        cin >> l >> r >> d;
        cout << (d < l ? d : (r / d + 1) * d) << endl;
    }
    return 0;
}