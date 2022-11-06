#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
bool v[maxn];

int main() {
    int n, x; cin >> n >> x;
    int ans = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (a < x) ++ans;
        if (a == x) ++b;
    }
    ans = x - ans;
    cout << ans + b << endl;
    return 0;
}