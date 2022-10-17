#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    ll ans = d * a + ((d - 1) / k) * t;
    ll minx = 0, maxx = max(((d - 1) / k) - 1, 0LL);
    // cout << minx << " " << maxx << '\n';
    ll lm = t + k * a - b * k;
    ll lb = k * a + d * b - k * b;
    // cout << lm << " " << lb << '\n';
    if (minx * k <= d - k) ans = min(ans, minx * lm + lb);
    if (maxx * k <= d - k) ans = min(ans, maxx * lm + lb);
    cout << ans << '\n';
}