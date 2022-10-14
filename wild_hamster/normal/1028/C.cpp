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
ll n,i,j,k,z,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[200500], b[200500], c[200500], d[200050];
multiset<ll> fa, fb, fc, fd;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        fa.insert(a[i]);
        fb.insert(b[i]);
        fc.insert(c[i]);
        fd.insert(d[i]);
    }
    for (int i = 0; i < n; i++) {
        fa.erase(fa.find(a[i]));
        fb.erase(fb.find(b[i]));
        fc.erase(fc.find(c[i]));
        fd.erase(fd.find(d[i]));
        auto itr = fa.end();
        itr--;
        ll A = *itr;
        itr = fb.end();
        itr--;
        ll B = *itr;
        itr = fc.begin();
        ll C = *itr;
        itr = fd.begin();
        ll D = *itr;
        if (A <= C && B <= D) {
            cout << A << " " << B << endl;
            return 0;
        }
        fa.insert(a[i]);
        fb.insert(b[i]);
        fc.insert(c[i]);
        fd.insert(d[i]);
    }
    return 0;
}