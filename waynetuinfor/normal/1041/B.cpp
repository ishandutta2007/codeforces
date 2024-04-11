#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, x, y; cin >> a >> b >> x >> y;
    long long g = __gcd(x, y);
    x /= g, y /= g;
    cout << min(a / x, b / y) << endl;
}