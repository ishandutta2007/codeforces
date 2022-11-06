#include <bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], pos[maxn];
long long ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    double tot = 0.0;
    double ch = (long long)n * (long long)(n + 1) - n;
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i - 1] + i - pos[a[i]];
        pos[a[i]] = i;
        tot += ans[i];
    }
    // cout << tot << endl;
    tot *= (double)2.0; tot -= n;
    cout << fixed << setprecision(20) << tot / ch << endl;
    return 0;
}