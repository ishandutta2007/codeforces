#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    assert(a <= b);
    long long t = 1ll;
    for (long long i = a + 1; i <= b; ++i) {
        t *= (i % 10); t %= 10;
        if (t == 0) break;
    }
    cout << t << endl;
    return 0;
}