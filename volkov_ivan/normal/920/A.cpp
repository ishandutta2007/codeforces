#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int main() {
    int n, k, t, x, now, left, right, minimum = 300, ans = 300, center, last;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        left = right = minimum = ans = 300;
        center = -300;
        for (int j = 0; j < k; j++) {
            cin >> now;
            if (j == 0) {
                left = now;
            }
            if (j == k - 1) {
                right = n - now + 1;
            }
            if (j > 0) {
                center = max(center, (int) ceil(((long double) now - last - 1) / 2) + 1);
            }
            last = now;
        }
        if (k <= 1) {
            cout << max(left, right) << endl;
        } else {
            cout << max(max(left, right), center) << endl;
        }
    }
    return 0;
}