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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer, cnt,v,tot,x,y,xx, yy,INF, sz;
vector<ll> mag;
int a[300500], b[300500], c[600500], pa[600500];
multiset<ll> f1, f2;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        f1.insert(a[i]);
        f2.insert(b[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f1.erase(f1.find(a[i]));
        f2.erase(f2.find(b[i]));
        auto itr = f1.end();
        itr--;
        int l = *itr;
        itr = f2.begin();
        int r = *itr;
        if (l <= r)
            ans = max(ans, r-l);
        f1.insert(a[i]);
        f2.insert(b[i]);
    }
    cout << ans << endl;
    return 0;
}