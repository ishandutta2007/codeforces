#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int id[maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = s + 1; j <= s + a[i]; ++j) id[j] = i;
        s += a[i];
    }
    int m; cin >> m; while (m--) {
        int x; cin >> x; cout << id[x] << endl;
    }
    return 0;
}