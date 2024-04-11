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
#define MOD 998244353
#define ROW 5
#define COL 30000
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,y,INF, ans;
ll a[1200005], res[1205000];
pii b[1205000], t[1205000];
pair<pii, ll> queries[500500];
map<ll, ll> lst;

void modify(int p, pii value) {  // set value at position p
    //cout << p << " " << value.X << " " << value.Y << endl;
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

pii query(int l, int r) {  // sum on interval [l, r)
  pii res = mp(MOD, MOD);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(res, t[--r]);
  }
  return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        modify(i, mp(MOD, MOD));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        queries[i] = mp(mp(r, l), i);
    }
    sort(queries, queries + q);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (b[a[i]].X == 0 && b[a[i]].Y == 0) {
            b[a[i]].Y = i;
            modify(i, mp(-1, a[i]));
            b[a[i]].X = -1;
        } else {
            modify(b[a[i]].Y, mp(MOD, MOD));
            b[a[i]].X = b[a[i]].Y;
            b[a[i]].Y = i;
            modify(i, mp(b[a[i]].X, a[i]));
        }
        while (j < q && queries[j].X.X == i) {
            ll l = queries[j].X.Y;
            ll num = queries[j].Y;

            pii mag = query(l, i+1);
            //cout << l << " " << i << " " << mag.X << " " << mag.Y << endl;
            if (mag < mp(l-1, MOD))
                res[num] = mag.Y;
            j++;
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}