#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int x = abs(a - b);
        int sol = 0, sum = 0;
        while (sum < x || sum % 2 != x % 2) {
            sum += ++sol;
        }
        cout << sol << '\n';
    }
}