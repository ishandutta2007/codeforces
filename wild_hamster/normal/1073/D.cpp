#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
ll a[200500];
ll t[400500];
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
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
    //freopen("input.txt", "r", stdin);
    cin >> n;
    long long T;
    cin >> T;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        t[n+i] = a[i];
        sum += a[i];
    }
    build();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p = T/sum;
        ans += p*(n-i);
        T %= sum;
        int l = 0, r = n-1;
        while (l < r) {
            ll mid = ((l+r)>>1);
            ll s = query(0, mid+1);
            //cout << i << " " << mid << " " << s << endl;
            if (s > T)
                r = mid;
            else
                l = mid+1;
        }
        sum -= a[l];
        //cout << l << " " << sum << endl;
        modify(l, 0);
    }
    cout << ans << endl;
    return 0;
}