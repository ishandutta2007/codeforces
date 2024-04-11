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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
pair<pii,ll> a[300500];
ll t[1005000];
vector<ll> f;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = MOD;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(res, t[--r]);
  }
  return res;
}
bool cmp(pair<pii,ll> x, pair<pii,ll> y) {
    if (x.X.X < y.X.X)
        return true;
    if (x.X.X > y.X.X)
        return false;
    if (x.X.Y < y.X.Y)
        return false;
    if (x.X.Y > y.X.Y)
        return true;
    return (x.Y < y.Y);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].X.X, &a[i].X.Y);
        a[i].Y = i+1;
    }
    sort(a, a+n, cmp);
    for (int i = n; i < 2*n; i++)
        t[i] = a[i-n].X.Y;
    build();
    for (int i = 0; i < n; i++) {
        ll pos = upper_bound(a+i+1, a+n, mp(mp(a[i].X.Y, MOD), 0))-a;
        ll min1 = query(i+1, pos);
        if (min1 <= a[i].X.Y) {
            for (int j = i+1; j < n; j++) {
                if (a[j].X.X >= a[i].X.X && a[j].X.Y <= a[i].X.Y) {
                    cout << a[j].Y << " " << a[i].Y << endl;
                    return 0;
                }
            }
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}