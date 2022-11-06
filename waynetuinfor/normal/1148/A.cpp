#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, ab; cin >> a >> b >> ab;
    long long ans = min(a, b) * 2 + 2 * ab;
    long long c = min(a, b);
    a -= c, b -= c;
    if (b > 0 || a > 0) ++ans;
    cout << ans << endl;
}