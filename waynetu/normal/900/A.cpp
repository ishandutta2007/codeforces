#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int p = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (x > 0) ++p;
        else ++b;
    }
    if (p <= 1 || b <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}