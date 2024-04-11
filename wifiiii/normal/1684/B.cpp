#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll z = c, y = c * c + b, x = y + a;
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}