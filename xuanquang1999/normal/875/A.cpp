#include <iostream>

using namespace std;

int main() {
    int x; cin >> x;

    int ans[100], n = 0;
    for(int sum = 99; sum > 0; --sum) {
        int y = x-sum, d = 0;
        while (y > 0) {
            d += y%10;
            y /= 10;
        }
        if (d == sum)
            ans[n++] = x-sum;
    }

    cout << n << endl;
    for(int i = 0; i < n; ++i) cout << ans[i] << endl;
}