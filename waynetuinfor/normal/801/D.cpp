#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
long double x[maxn], y[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    long double ans = 1e18 + 10;
    for (int i = 0; i < n; ++i) {
        int a = i, b = (i + 1) % n, c = (i + 2) % n;
        pair<long double, long double> v1 = make_pair(x[a] - x[c], y[a] - y[c]), v2 = make_pair(x[b] - x[c], y[b] - y[c]);
        long double area = fabs(v1.first * v2.second - v1.second * v2.first); 
        long double len = sqrt(v1.first * v1.first + v1.second * v1.second);
        ans = min(ans, area / len / 2);
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}