#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 2; i <= N; ++i) {
        ll k = N / i;
        ans += k * (k + 1) / 2 - 1;
    }

    cout << ans * 4 << endl;
    return 0;
}