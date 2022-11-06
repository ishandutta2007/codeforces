#include <bits/stdc++.h>
using namespace std;

const int maxn = 4000 + 10;
bool v[maxn];

int main() {
    int x, k; cin >> x >> k;
    while (k--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            v[a] = v[b] = true;
        } else {
            int a; cin >> a;
            v[a] = true;
        }
    }
    int ans1 = 0;
    for (int i = 1; i < x; ++i) if (!v[i]) ++ans1;
    int ans2 = 0;
    for (int i = 1; i < x; ++i) {
        if (!v[i]) {
            ++ans2;
            if (!v[i + 1]) v[i + 1] = true;
        }
    }
    cout << ans2 << ' ' << ans1 << endl;
}