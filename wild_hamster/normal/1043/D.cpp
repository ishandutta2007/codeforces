#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define INF 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,x,y,n,m,  x1,y1,x2,y2,z;
ll a[100500][15], b[100500][15];
string s;
ll pos[15];
int main() {
    //freopen("input.txt", "r", stdin);
    //srand(time(0));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j][i]);
            b[a[j][i]][i] = j;
        }
    }
    int r = -1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > r) {
            r = i;
            for (int j = 1; j < m; j++) {
                pos[j] = b[a[i][0]][j];
            }
        }
        while (1) {
            int flag = 1;
            if (r == n-1)
                break;
            for (int j = 1; j < m; j++) {
                if (pos[j] == n-1 || a[pos[j]+1][j] != a[r+1][0])
                    flag = 0;
            }
            if (!flag)
                break;
            if (flag) {
                r++;
                for (int j = 1; j < m; j++)
                    pos[j]++;
            }
        }
        //cout << r << endl;
        ans += r-i+1;
    }
    cout << ans << endl;
    return 0;
}