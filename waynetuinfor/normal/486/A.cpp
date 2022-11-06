#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long ans = -1 * ((n + 1) / 2);
    if (!(n & 1)) ans += n;
    cout << ans << endl;
}