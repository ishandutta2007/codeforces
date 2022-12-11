#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 2e3 + 10;
ii f[N][N];
int h[N][N], a[N][N];

int n, m, limL, limR, sx, sy;

deque<ii> q;
int solve() {
    h[sx][sy] = 1;
    q.push_back(ii(sx,sy));
    int ans = 0;
    while (!q.empty()) {
        ii cur = q.front(); q.pop_front();
        ans++;
        for(int dx = -1; dx <= 1; dx+=2) {
            if (a[cur.X + dx][cur.Y] && !h[cur.X + dx][cur.Y]){
                h[cur.X + dx][cur.Y] = 1;
                f[cur.X + dx][cur.Y] = f[cur.X][cur.Y];
                q.push_front(ii(cur.X + dx, cur.Y));
            }
        }
        if (f[cur.X][cur.Y].X < limL) {
            if (a[cur.X][cur.Y - 1] && !h[cur.X][cur.Y - 1]){
                h[cur.X][cur.Y - 1] = 1;
                f[cur.X][cur.Y - 1] = f[cur.X][cur.Y];
                f[cur.X][cur.Y - 1].X++;
                q.push_back(ii(cur.X, cur.Y - 1));
            }
        }
        if (f[cur.X][cur.Y].Y < limR) {
            if (a[cur.X][cur.Y + 1] && !h[cur.X][cur.Y + 1]){
                h[cur.X][cur.Y + 1] = 1;
                f[cur.X][cur.Y + 1] = f[cur.X][cur.Y];
                f[cur.X][cur.Y + 1].Y++;
                q.push_back(ii(cur.X, cur.Y + 1));
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> limL >> limR;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            a[i][j] = (s[j - 1] == '.');
        }
    }
    cout << solve();
}