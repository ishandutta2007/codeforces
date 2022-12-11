#include <iostream>

using namespace std;

int main() {
    long long a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    long long cnta = 0, cntb = 0;
    cnta = 2 * x + y;
    cntb = y + 3 * z;
    long long ans = max(0LL, cnta - a) + max(0LL, cntb - b);
    cout << ans << endl;
    return 0;
}