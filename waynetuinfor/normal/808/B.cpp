#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a, s[i] = s[i - 1] + a;
    // double ans = 0.0;
    long long sum = 0;
    for (int i = k; i <= n; ++i) sum += s[i] - s[i - k];
    cout << fixed << setprecision(10) << (double)sum / (double)(n - k + 1) << endl;
    return 0;
}