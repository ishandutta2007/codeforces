#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> a(n, vector<char>(m));
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            cnt += a[i][j] == '*';
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(j * n + i < cnt) ans += a[i][j] == '.';
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        // (x, y) -> y * n + x
        --x, --y;
        if(a[x][y] == '.') {
            a[x][y] = '*';
            if(y * n + x < cnt) ans -= 1;
            int cy = cnt / n, cx = cnt % n;
            if(a[cx][cy] == '.') ans += 1;
            cnt += 1;
        } else {
            cnt -= 1;
            int cy = cnt / n, cx = cnt % n;
            if(a[cx][cy] == '.') ans -= 1;
            a[x][y] = '.';
            if(y * n + x < cnt) ans += 1;
        }
        cout << ans << '\n';
    }
}