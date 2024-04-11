#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int sol, tmp;
    if (e > f) {
        tmp = min(a, d);
        sol = tmp * e;
        d -= tmp;
        sol += min({b, c, d}) * f;
    } else {
        tmp = min({b, c, d});
        sol = tmp * f;
        d -= tmp;
        sol += min(a, d) * e;
    }
    cout << sol << '\n';
}