#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int r = k - 1; r > 0; --r) {
        if (n % r == 0) {
            int d = n / r;
            cout << d * k + r << endl;
            return 0;
        }
    }
    return 0;
}