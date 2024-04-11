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
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz;
ll a[200500], b[200500], c[200500], d[200500], t[400500];
map<ll, ll> compr;

void modify(int p, int value) {  // set value at position p
  for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    ll T;
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        if (i == 0)
            b[i] = a[i];
        else
            b[i] = b[i-1] - a[i-1];
        c[i] = b[i];
        compr[b[i]] = 0;
    }
    sort(c, c+n);
    int i = 0;
    int sz = 0;
    for (auto itr = compr.begin(); itr != compr.end(); itr++) {
        compr[(*itr).X] = i++;
        sz = i;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        modify(compr[b[i]], 1);
        //cout << b[i] << endl;
        ll val = upper_bound(c, c+n, T+(b[i]-a[i])-1)-c;
        if (val == n)
            val = sz;
        else
            val = compr[c[val]];
        ans += query(0, val);
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}