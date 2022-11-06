#include <bits/stdc++.h>
using namespace std;

const double inf = 1e9;

int main() {
    int n, m; cin >> n >> m;
    double bst = inf;
    while (n--) {
        int a, b; cin >> a >> b;
        bst = min(bst, 1.0 * a / b);
    }
    cout << fixed << setprecision(20) << bst * m << endl;
}