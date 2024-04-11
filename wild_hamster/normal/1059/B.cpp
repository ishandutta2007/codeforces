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
ll i,j,k,z,q,timer, v,x,y,xx, yy,INF, sz,n,m, cnt, even, flag, ans;
vector<vector<pii> > g;
char c[1005][1005], a[1005][1005];
int used[1005][1005];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%s", c[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            a[i][j] = '.';
            if (i == 0 || i == n-1 || j == 0 || j == m-1)
                used[i][j] = 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (c[i][j] == '.') {
                for (int k = -1; k <= 1; k++)
                    for (int l = -1; l <= 1; l++)
                        if (k != 0 || l != 0) {
                            if (i+k >= 0 && i+k < n && j+l >= 0 && j+l < m)
                                used[i+k][j+l] = 1;
                        }
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!used[i][j]) {
                for (int k = -1; k <= 1; k++)
                    for (int l = -1; l <= 1; l++)
                        if (k != 0 || l != 0)
                            a[i+k][j+l] = '#';
            }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        if (a[i][j] != c[i][j]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}