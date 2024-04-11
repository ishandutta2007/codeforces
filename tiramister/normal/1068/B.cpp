#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll b;
    cin >> b;
    int ans = 0;
    for (ll i = 1; i * i <= b; ++i) {
        if (b % i > 0) continue;
        ++ans;
        if (i * i != b) ++ans;
    }

    cout << ans << endl;
    return 0;
}