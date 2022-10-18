#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nTest;
    cin >> nTest;

    while (nTest--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long ans = (x2 - x1 + 1) * (y2 - y1 + 1);
        ans -= (x2 - x1) + (y2 - y1);

        cout << ans << endl;
    }
}