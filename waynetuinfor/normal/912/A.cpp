#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, x, y, z; cin >> a >> b >> x >> y >> z;
    long long c = x * 2 + y, d = y + z * 3;
    cout << max(0ll, c - a) + max(0ll, d - b) << endl;
}