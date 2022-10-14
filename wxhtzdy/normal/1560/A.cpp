#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int tt;
    cin >> tt;

    while (tt--) {
        int k;
        cin >> k;

        for (int i = 1; ; i++) {
            if (i % 3 == 0 || i % 10 == 3) continue;

            k--;
            if (k == 0) {
                cout << i << '\n';
                break;
            }
        }
    }

}