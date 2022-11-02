#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int b, k;
    cin >> b >> k;

    int a[k];
    for (int i = 0; i < k; ++i) cin >> a[i];

    if (b & 1) {
        cout << (accumulate(a, a + k, 0) & 1 ? "odd" : "even") << endl;
    } else {
        cout << (a[k - 1] & 1 ? "odd" : "even") << endl;
    }
    return 0;
}