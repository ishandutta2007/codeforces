#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, g, b;
        cin >> n >> g >> b;
        long long cyc = (n + 1) / 2 / g;
        long long rem = (n + 1) / 2 % g;
        cout << max((long long)n, (cyc - (rem == 0)) * b + cyc * g + ((n + 1) / 2 % g)) << '\n';
    }
}