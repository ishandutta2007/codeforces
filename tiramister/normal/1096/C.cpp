#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;

        for (int n = 3; n <= 1000; ++n) {
            if (t * n % 180 == 0 && t * n / 180 <= n - 2) {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}