#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n - 1 << endl;
    } else {
        cout << n * 1LL * (m - 1) << endl;
    }
}