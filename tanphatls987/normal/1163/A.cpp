#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m <= 1) cout << "1";
    else {
        if (m <= n / 2) cout << m;
        else {
            int tol = (n + 1) / 2;
            cout << n / 2 - (m - tol);
        }
    }
}