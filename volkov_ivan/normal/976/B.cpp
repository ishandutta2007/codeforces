#include <iostream>
 
using namespace std;
 
int main() {
    long long n, m, k, a, b;
    cin >> n >> m >> k;
    if (k <= n - 1) {
        cout << 1 + k << ' ' << 1 << endl;
        return 0;
    }
    k -= n - 1;
    k--;
    a = n - (k / (m - 1));
    k = k % (m - 1);
    if ((n - a) % 2 == 0) {
        b = 2 + k;
    } else {
        b = m - k;
    }
    cout << a << ' ' << b << endl;
    return 0;
}