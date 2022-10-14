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
const int C = 5150000;
ll n,i,j,k,z,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[400500], b[400500];
ll primes[5252525];
vector<ll> cp[5252525];
pair<pii, ll> queries[1212121];
ll T[15][2*C+5];
ll lst[C+5][8];
ll ans[1151515];

void build(int pos) {  // build the tree
  for (int i = C - 1; i > 0; --i) T[pos][i] = max(T[pos][i<<1], T[pos][i<<1|1]);
}

void modify(int pos, int p, int value) {  // set value at position p
    //cout << pos << " " << p << " " << value << endl;
  for (T[pos][p += C] = value; p > 1; p >>= 1) T[pos][p>>1] = max(T[pos][p], T[pos][p^1]);
}

int query(int pos, int l, int r) {  // sum on interval [l, r)
    //cout << "query " << pos << " " << l << " " << r << endl;
  int res = -1;
  for (l += C, r += C; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, T[pos][l++]);
    if (r&1) res = max(res, T[pos][--r]);
  }
  //cout << res << endl;
  return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 2; i <= C; i++)
        primes[i] = 1;
    for (int i = 2; i <= C; i++) {
        if (primes[i]) {
            cp[i].push_back(i);
            for (int j = i*2; j <= C; j += i) {
                primes[j] = 0;
                int x = j;
                int val = 0;
                while (x % i == 0) {
                    x /= i;
                    val ^= 1;
                }
                if (val)
                    cp[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        scanf("%d %d",&queries[i].X.Y, &queries[i].X.X);
        queries[i].X.X--;
        queries[i].X.Y--;
        queries[i].Y = i;
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < C; j++) {
            T[i][j+C] = -1;
        }
        build(i);
    }
    for (int i = 0; i < C; i++)
        for (int j = 0; j < 8; j++)
            lst[i][j] = -1;
    sort(queries, queries+m);
    ll pnt = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        int j = cp[x].size();
        for (int k = 0; k < (1<<j); k++) {
            ll val = 1, bits = j;
            for (int l = 0; l < j; l++)
                if ((k>>l)&1) {
                    val *= cp[x][l];
                    bits--;
                }
            for (int t = 0; t < 8; t++) {
                if (lst[val][t] != -1) {
                    //ans[bits+t][val] = lst[val][t];
                    ll val1 = query(bits+t, val, val+1);
                    if (val1 < lst[val][t])
                    modify(bits+t, val, lst[val][t]);
                }
            }
            //cout << i << " " << val << " " << bits << endl;
            lst[val][bits] = max(i, lst[val][bits]);
        }
        while (pnt < m && queries[pnt].X.X == i) {
            for (int j = 0; j <= 14; j++) {
                if (query(j, 0, C) >= queries[pnt].X.Y) {
                    ans[queries[pnt].Y] = j;
                    break;
                }
            }
            pnt++;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d\n",ans[i]);
    return 0;
}