#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int c, sum;
        cin >> c >> sum;
        int k = sum / c;
        cout << (sum % c) * (k + 1) * (k + 1) + (c - sum % c) * k * k << '\n';
    }
}