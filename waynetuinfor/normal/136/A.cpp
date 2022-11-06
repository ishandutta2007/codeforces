#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int ans[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p; cin >> p;
        ans[p] = i;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
}