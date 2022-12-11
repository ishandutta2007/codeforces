#include <iostream>

using namespace std;

int main() {
    int n, now;
    bool ok;
    cin >> n;
    int ans = -1000000000;
    for (int i = 0; i < n; i++) {
        cin >> now;
        ok = 1;
        for (int j = 0; j <= 1000; j++) {
            if (j * j == now) {
                ok = 0;
                break;
            }
        }
        if (ok) ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}