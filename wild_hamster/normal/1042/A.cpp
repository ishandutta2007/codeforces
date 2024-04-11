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
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz;
ll a[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    for (int i = 0; i < m; i++) {
        int min1 = MOD, id = 0;
        for (int j = 0; j < n; j++)
            if (a[j] < min1)
                min1 = a[j], id = j;
        a[id]++;
    }
    int ans1 = 0;
    ans += m;
    for (int i = 0; i < n; i++)
        ans1 = max(ans1, a[i]);
    cout << ans1 << " " << ans << endl;
    return 0;
}