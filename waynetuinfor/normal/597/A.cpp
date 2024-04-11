#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, a, b; cin >> k >> a >> b;
    long long c, d;
    if (a >= 0) c = (a % k == 0 ? a / k : a / k + 1);
    else c = a / k;
    if (b < 0) d = (b % k == 0 ? b / k : b / k - 1);
    else d = b / k;
    cout << d - c + 1 << endl;
    return 0;
}