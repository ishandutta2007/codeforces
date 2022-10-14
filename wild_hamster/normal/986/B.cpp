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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt,s;
vector<ll> g[100500], f[100500], ff;
ll a[1000500], t[4000500];

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
    }
    n += 2;
    ll ans = 0;
    for (int i = 1; i <= n-2; i++) {
        ans += query(a[i]+1, n);
        modify(a[i], 1);
    }
    if ((n+ans)%2==0) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }
    return 0;
}