#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 62; j++) {
            if (a[i] & (1LL << j)) {
                f[i]++;
            }
        }
    }
    long long ans = 0LL;
    vector<array<int, 2>> in(n + 1);
    in[0] = {1, 0};
    int p = 0;
    for (int i = 1; i <= n; i++) {
        p += f[i - 1];
        in[i][0] = in[i - 1][0];
        in[i][1] = in[i - 1][1];
        ++in[i][p % 2];
        int cnt = 0, mx = 0;
        for (int j = i; j >= max(i - 120, 1); j--) {
            mx = max(mx, f[j - 1]);
            cnt += f[j - 1];
            if (cnt % 2 == 0 && mx * 2 <= cnt) {
                ++ans;
            }
        }
        if (i - 122 >= 0) {
            ans += in[i - 122][p % 2];
        }
    }
    cout << ans;
}