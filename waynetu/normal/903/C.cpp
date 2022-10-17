#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
map<int, int> c;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ++c[a];
    }
    int ans = 0;
    for (auto it : c) ans = max(ans, it.second);
    cout << ans << endl;
}