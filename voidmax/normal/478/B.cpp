#include <iostream>
#include <vector>
#define int long long

using namespace std;

int n, m, z, s;

main() {
    cin >> n >> m;
    z = n / m;
    s = n - z * m;
    cout << (m - s) * (z - 1) * z / 2 + s * (z + 1) * z  / 2 << ' ';
    cout << (n - m + 1) * (n - m) / 2;
}