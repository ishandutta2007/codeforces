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
typedef long long ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, ans,x1,y1,x2,y2;
ll a[1015][1015];
void dfs(int x, int y) {
    if (a[x][y])
        return;
    a[x][y] = 1;
    if (x == x2 && y == y2) {
        cout << "YES" << endl;
        exit(0);
    }
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i != 0 || j != 0)
                dfs(x+i, y+j);
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> x >> y;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            a[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
    if (i != 0 || j != 0) {
        for (int k = 0; k < 1488; k++) {
            int nx = x+k*i;
            int ny = y+k*j;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                a[nx][ny] = 1;
        }
    }
    dfs(x1, y1);
    cout << "NO" << endl;
    return 0;
}