#include <iostream>
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int s = a + b + c;
        int maxi = max(max(a, b), c);
        bool good;
        if (s % 2 == 0) {
            good = (maxi * 2 <= s);
        } else {
            good = (maxi * 2 <= s + 1);
        }
        cout << (good ? "Yes" : "No") << endl;
    }
    return 0;
}