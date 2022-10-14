#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgjs
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
char a[1005000], b[1000500], s[1005000], t[1005000];
set<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            f.insert(1LL * i * (n/i) * (n/i-1) / 2 + n/i);
            if (i * i != n) {
                f.insert(1LL * (n/i) * i * (i-1) / 2 + i);
            }
        }
    }
    for (auto &x : f) {
        cout << x << " ";
    }
    return 0;
}