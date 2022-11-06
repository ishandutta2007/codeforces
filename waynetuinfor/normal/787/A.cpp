#include <bits/stdc++.h>
using namespace std;

bool v[105];

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    bool pos = false;
    for (int i = 0; ; ++i) {
        int ans = b - d + a * i;
        if (ans < 0) continue;
        if (ans % c == 0) return cout << b + a * i << '\n', 0;
        if (v[ans % c]) return cout << "-1\n", 0;
        v[ans % c] = true;
    }
    return 0;
}