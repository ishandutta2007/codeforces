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
ll a[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += (x-l)/k;
        l = x+y;
    }
    ans += (m-l)/k;
    cout << ans << endl;
    return 0;
}