#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, a[N];
int ans[N][N];
int p[N], pos[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) p[i] = i;

    sort(p + 1, p + n + 1, [&](int x, int y) {
        return a[x] < a[y];
    });

    for(int i = 1; i <= n; i++) pos[p[i]] = i;
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= a[p[i]]; j++) ans[i + 1 - j][i] = 1;
        for(int j = 1; j < i; j++) if (a[p[j]] == i) {
            ans[i + 1][j] = 1;
            a[p[j]]--;
        }
    }
    cout << n + 1 << '\n';
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= n; j++) cout << ans[i][pos[j]];
        cout << '\n';
    }
}