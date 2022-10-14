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
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    for (int i = 300; i >= 3; i--) {
        if (k >= i && m >= i-1 && n >= i-2) {
            cout << 3*i - 3 << endl;
            return 0;
        }
    }
    return 0;
}