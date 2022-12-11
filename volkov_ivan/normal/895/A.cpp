#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int x, y, summ, ans = 360;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        summ = 0;
        for (int j = i; j < n; j++) {
            summ += a[j];
            x = summ;
            y = 360 - summ;
            if (abs(x - y) < ans) {
                ans = abs(x - y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}