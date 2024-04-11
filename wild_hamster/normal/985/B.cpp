#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
char a[2005][2005];
ll b[2005];
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s",a[i]);
        for (int j = 0; j < m; j++)
            b[j] += a[i][j] - '0';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            b[j] -= (a[i][j] - '0');
        ll flag = 1;
        for (int j = 0; j < m; j++)
            if (b[j] == 0)
                flag = 0;
        if (flag) {
            cout << "YES" << endl;
            return 0;
        }
        for (int j = 0; j < m; j++)
            b[j] += (a[i][j] - '0');
    }
    cout << "NO" << endl;
    return 0;
}