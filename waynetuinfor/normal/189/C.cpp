#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], pos[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        pos[v] = i;
    }
    for (int i = 1; i <= n; ++i) a[i] = pos[a[i]];
    for (int i = 1; i <= n; ++i) {
        if (a[i] < a[i - 1]) return cout << n - i + 1 << endl, 0;
    }
    cout << 0 << endl;
    return 0;
}