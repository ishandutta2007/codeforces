#include <iostream>
#include <algorithm>
using namespace std;

int k2, k3, k5, k6;
long long ans;

int main() {
    cin >> k2 >> k3 >> k5 >> k6;
    ans += 256 * min({ k2, k5, k6 });
    k2 -= min({ k2, k5, k6 });
    k5 -= min({ k2, k5, k6 });
    k6 -= min({ k2, k5, k6 });
    ans += 32 * min(k2, k3);
    cout << ans << '\n';
    return 0;
}