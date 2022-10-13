#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long s[1005][1005];
long long m[1005][1005];

int main() {
    int n; cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0LL, mn = 0LL;
        for (int j = i; j < n; j++) {
            if (j % 2 == 0) sum += c[j];
            else sum -= c[j];
            mn = min(mn, sum);
            s[i][j] = sum;
            m[i][j] = mn;
        }
    }
    for (int l = 0; l < n; l += 2) {
        for (int r = l + 1; r < n; r += 2) {
            long long sum = s[l + 1][r - 1];
            long long mn = m[l + 1][r - 1];
            long long st = max({1LL, -mn, 1LL - sum});
            long long en = min({c[l] * 1LL, c[r] * 1LL - sum});
            ans += max(0LL, en - st + 1);
        }
    }
    cout << ans << "\n";
}