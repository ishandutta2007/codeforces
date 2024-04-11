#include <iostream>

using namespace std;

const int N = 2e5 + 7;

long long a[N], pref[N];

int my_bs(long long x, int n) {
    int l = -1, r = n, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (pref[m] > x) r = m;
        else l = m;
    }
    return r;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    long long k;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
    long long last = 0;
    for (int i = 0; i < q; i++) {
        cin >> k;
        int pos = my_bs(k + last, n);
        if (pos != n) {
            cout << n - pos << "\n";
            last += k;
        } else {
            cout << n << "\n";
            last = 0;
        }
    }
    return 0;
}