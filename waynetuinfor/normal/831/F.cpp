#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
const long long inf = 1e18 + 1;
int a[maxn], n;
long long k;

bool check(long long);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k; long long t = k;
    for (int i = 0; i < n; ++i) cin >> a[i], t += a[i];
    long long ans = 0;
    for (long long i = 1; i <= t; ++i) {
        if (check(t / i)) ans = max(ans, t / i);
        i = t / (t / i);
    } cout << ans << endl;
    return 0;
}

bool check(long long d) {
    // cout << "check d = " << d << endl;
    long long cut = 0;
    for (int i = 0; i < n; ++i) {
        long long par = (a[i] % d == 0 ? a[i] / d : a[i] / d + 1);
        cut += par * d - a[i];
    }
    // cout << "cut = " << cut << endl;
    return cut <= k;
}