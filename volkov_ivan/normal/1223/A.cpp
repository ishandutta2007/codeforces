#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long n;
        cin >> n;
        if (n == 2) {
            cout << 2 << endl;
            continue;
        }
        if (n % 2 == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}