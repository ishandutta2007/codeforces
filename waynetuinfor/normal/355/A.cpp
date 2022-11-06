#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, d; cin >> k >> d;
    if (d == 0) {
        if (k == 1) cout << 0 << endl;
        else cout << "No solution" << endl;
        return 0;
    }
    cout << d;
    for (int i = 0; i < k - 1; ++i) cout << 0;
    cout << endl;
    return 0;
}