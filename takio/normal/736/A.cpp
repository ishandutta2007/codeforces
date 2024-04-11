#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, f[120];
    cin >> n;
    long long c = 0, t = 1;
    f[1] = 2, f[2] = 3;
    for (int i = 3; i < 120; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 1; i < 120; i++) {
        if (f[i + 1] > n) {
            cout << i;
            break;
        }
    }
}