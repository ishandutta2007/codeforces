#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;

    ll s[n];
    cin >> s[0];
    for (int i = 1; i < n; ++i) {
        ll a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }

    ll sum = 0;
    for (int i = 0; i < q; ++i) {
        ll k;
        cin >> k;
        sum += k;
        if (upper_bound(s, s + n, sum) == s + n) sum = 0;
        cout << s + n - upper_bound(s, s + n, sum) << '\n';
    }

    return 0;
}