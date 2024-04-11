#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int b[N];  // 1
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        b[i] = __builtin_popcountll(a);
    }

    ll sum[N + 1], psum[N + 1];
    // sum[i]  = i
    // psum[i] = j<=isum[j]

    sum[0] = psum[0] = 0;
    for (int i = 0; i < N; ++i) {
        sum[i + 1] = sum[i] + b[i];
        psum[i + 1] = psum[i] + (sum[i + 1] % 2);
    }

    ll ans = 0;
    for (int r = 1; r <= N; ++r) {
        // sum[l]sum[r]
        if (sum[r] % 2 == 1) {
            ans += psum[r - 1];
        } else {
            ans += r - psum[r - 1];
        }
    }

    // 60
    for (int r = 0; r <= N; ++r) {
        for (int l = max(0, r - 60); l < r; ++l) {
            int s = sum[r] - sum[l];  // b[l]+b[l+1]+...+b[r-1]
            if (s % 2 != 0) continue;

            int ma = *max_element(b + l, b + r);  // max(b[l], b[l+1], ..., b[r-1])
            if (ma * 2 > s) --ans;
        }
    }

    cout << ans << endl;
    return 0;
}