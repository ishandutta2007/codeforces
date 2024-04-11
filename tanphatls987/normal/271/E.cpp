#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

long long cover(long long use, long long m) {
    long long ans = 0;
    //cout << use << '\n';
    while (use <= m - 1) {
         ans += m - use;
         use <<= 1;
    }
    return ans;
}
long long solve() {
    int step = 0;
    for(int i = 1; i <= n; i++) step = __gcd(step, a[i] - 1);

    long long ans = 0;
    for(int i = 1; i * i <= step; i++) if (step % i == 0) {
        if (i % 2) ans += cover(i, m);
        if (step / i != i && step / i % 2) 
            ans += cover(step / i, m);
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve();
}