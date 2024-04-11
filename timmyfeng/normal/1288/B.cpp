#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        long long sol = floor(log10(b + 1)) * a;
        cout << sol << "\n";
    }
}