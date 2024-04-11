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
    int t;
    cin >> t;
    while (t--) {
        ll x,y;
        cin >> x >> y;
        if (x - y != 1) {
            cout << "NO" << endl;
            continue;
        }
        int flag = 1;
        for (int i = 2; i < min(1488228LL, x+y); i++) {
            if ((x+y) % i == 0) {
                flag = 0;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
    }
    return 0;
}