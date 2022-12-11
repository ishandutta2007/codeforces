#include <iostream>

using namespace std;

int min_prime(int n) {
    int i = 2;
    while (i * i <= n) {
        if ((n % i) == 0) return i;
        i++;
    }
    return n;
}

int main() {
    int p, y;
    cin >> p >> y;
    for (int i = y; i >= max(2, p); i--) {
        if (min_prime(i) > p) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}