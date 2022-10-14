#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
char a[2005][2005];
int d[2005][2005], used[2005][2005];
int dirs[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
vector<pii> f, f1;
bool in_range(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (a[x][y] == '*')
        return false;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> r >> c;
    r--;c--;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (int i = 0;i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = MOD;
    d[r][c] = 0;
    f.push_back(mp(r,c));
    i = 0;
    while (i < f.size()) {
        pii v = f[i++];
        if (!used[v.X][v.Y]) {
            used[v.X][v.Y] = 1;
            for (int i = 0; i < 3; i++) {
                int nx = v.X + dirs[i][0];
                int ny = v.Y + dirs[i][1];
                if (in_range(nx, ny) && d[v.X][v.Y] < d[nx][ny]) {
                    d[nx][ny] = d[v.X][v.Y];
                    f.push_back(mp(nx, ny));
                }
            }
            for (int i = 3; i < 4; i++) {
                int nx = v.X + dirs[i][0];
                int ny = v.Y + dirs[i][1];
                if (in_range(nx, ny) && d[v.X][v.Y] + 1 < d[nx][ny]) {
                    d[nx][ny] = d[v.X][v.Y] + 1;
                    f1.push_back(mp(nx, ny));
                }
            }
        }
        if (i == f.size()) {
            i = 0;
            f.clear();
            for (int i = 0; i < f1.size(); i++)
                f.push_back(f1[i]);
            f1.clear();
        }
    }
    int ans = 0;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            int diff = j-c;
            int val = d[i][j];
            if (val <= x && val + diff <= y)
                ans++;
            //cout << d[i][j] << " ";
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}