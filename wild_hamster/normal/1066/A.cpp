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
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
vector<pii> f, f1;
int a[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int L, v, l, r;
        cin >> L >> v >> l >> r;
        int ans = L/v;
        ans -= r/v;
        ans += (l-1)/v;
        cout << ans << endl;
    }
    return 0;
}