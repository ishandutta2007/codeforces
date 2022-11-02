#include <iostream>

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    int l[2], r[2], t[2];
    for (int i = 0; i < 2; ++i) {
        cin >> l[i] >> r[i] >> t[i];
        ++r[i];
    }

    int s = gcd(t[0], t[1]);

    if (l[1] < l[0]) {
        swap(l[0], l[1]);
        swap(r[0], r[1]);
    }

    int ans = 0;

    int sl = (l[1] - l[0]) / s * s;
    l[1] -= sl, r[1] -= sl;
    ans = max(ans, min(r[0], r[1]) - l[1]);

    l[1] -= s, r[1] -= s;
    ans = max(ans, min(r[0], r[1]) - l[0]);

    cout << ans << endl;
    return 0;
}