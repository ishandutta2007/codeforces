#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;
    reverse(b.begin(), b.end());
    long long ans = (long long) 1e18;
    function<long long(vector<long long>)> Solve = [&](vector<long long> c) {
        long long res = 0;
        int sz = (int) c.size();
        long long pre = 0;
        for (int i = 0; i < sz; i++) {
            long long k = pre / c[i];
            long long now = k * c[i];
            while (pre >= now) {
                now += c[i];
                k++;
            }
            res += k;
            pre = now;
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        long long t = Solve(vector<long long>(a.begin() + i + 1, a.end()));
        t += Solve(vector<long long>(b.begin() + n - i, b.end()));
        ans = min(ans, t);
    }
    cout << ans << '\n';
    return 0;
}