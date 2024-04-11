#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, sx, sy, tx, ty;
        cin >> n >> m >> sx >> sy >> tx >> ty;
        --sx, --sy, --tx, --ty;
        int dx = 1, dy = 1, ans = 0;
        while(sx != tx && sy != ty) {
            if(sx + dx == n || sx + dx < 0) dx = -dx;
            if(sy + dy == m || sy + dy < 0) dy = -dy;
            sx += dx, sy += dy, ans += 1;
        }
        cout << ans << '\n';
    }
}