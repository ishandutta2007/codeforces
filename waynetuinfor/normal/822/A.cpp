#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    long long ans = 1LL;
    for (int i = 1; i <= a; ++i) ans *= (long long)i;
    cout << ans << endl;
    return 0;
}