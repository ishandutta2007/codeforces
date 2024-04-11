#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        int n, k;
        cin >> n >> k;

        while (n > 0) {
            for (int i = 0; i < k && n > 0; ++i, --n) {
                cout << (char)('a' + i);
            }
        }
        cout << endl;
    }
    return 0;
}