#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n[2];
int a[2][N];
long long solve() {
    if (a[0][n[0]] > a[1][1]) return -1;
    long long ans = 0;
    for(int i = 1; i <= n[1]; i++) ans += a[1][i];
    for(int i = 1; i < n[0]; i++) ans += 1LL * n[1] * a[0][i];
    if (a[0][n[0]] < a[1][1]) ans += a[0][n[0]] - a[0][n[0] - 1];
    return ans;
}
int main() {
    cin >> n[0] >> n[1];
    for(int j = 0; j <= 1; j++) {
        for(int i = 1; i <= n[j]; i++) cin >> a[j][i];
        sort(a[j] + 1, a[j] + n[j] + 1);
    }
    cout << solve();
}