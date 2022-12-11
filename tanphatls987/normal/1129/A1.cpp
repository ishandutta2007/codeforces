#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;

int n, m;
int h[N];
int D[N];
int main() {
    cin >> n >> m;
    fill(D, D + n, n + 2);
    while (m--) {
        int x, y; cin >> x >> y;
        x--, y--;
        h[x]++;

        int dist = (y - x + n) % n;
        D[x] = min(D[x], dist);
    }

    for(int st = 0; st < n; st++) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int pos = (st + i) % n;
            if (!h[pos]) continue;
            ans = max(ans, i + (h[pos] - 1) * n + D[pos]);
        }
        cout << ans << " ";
    }
}