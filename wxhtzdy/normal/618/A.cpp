#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    for (int i = 25; i >= 0; i--) {
        if (n & (1 << i)) {
            cout << i + 1 << " ";
        }
    }
    cout << '\n';
}