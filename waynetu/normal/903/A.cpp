#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        bool ans = false;
        for (int i = 0; i * 7 <= x; ++i) {
            if ((x - i * 7) % 3 == 0) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}