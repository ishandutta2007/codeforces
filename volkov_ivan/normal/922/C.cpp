#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= min(1000000LL, k); i++) {
        if ((n % i) != i - 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}