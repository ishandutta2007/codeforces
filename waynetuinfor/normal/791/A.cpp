#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int t = 0;
    while (a <= b) ++t, a *= 3, b *= 2;
    cout << t << '\n';
    return 0;
}