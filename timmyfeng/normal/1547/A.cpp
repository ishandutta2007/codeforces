#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;

        bool blocked = (xa == xb && xb == xc && min(ya, yb) < yc && yc < max(ya, yb)) ||
            (ya == yb && yb == yc && min(xa, xb) < xc && xc < max(xa, xb));

        cout << abs(xa - xb) + abs(ya - yb) + (blocked ? 2 : 0) << "\n";
    }
}