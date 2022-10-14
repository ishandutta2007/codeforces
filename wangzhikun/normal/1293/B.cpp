#include <bits/stdc++.h>
 
using namespace std;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; ++i) ans += 1.0 / i;
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}