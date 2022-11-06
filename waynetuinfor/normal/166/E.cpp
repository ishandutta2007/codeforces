#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    int a = 1, b = 0;
    for (int i = 0; i < n; ++i) {
        int ta = 3 * 1ll * b % mod;
        int tb = (2 * 1ll * b + a) % mod;
        a = ta; b = tb;
    }
    cout << a << endl;
}