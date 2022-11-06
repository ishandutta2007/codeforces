#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    long long ans = 0;
    while (a != b && a && b) {
        if (a < b) swap(a, b);
        ans += (a / b); a %= b;
    }
    if (a && b && a == b) ++ans; 
    cout << ans << endl;
    return 0;
}