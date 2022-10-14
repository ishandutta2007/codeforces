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
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom;
int a[500500], b[500500], fac[500500], invfac[500500];
int binpow(int x, int y) {
    if (y == 0)
        return 1;
    int tmp = binpow(x, y/2);
    tmp = 1LL*tmp*tmp%MOD;
    if (y % 2 == 0)
        return tmp;
    return 1LL*x*tmp%MOD;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //inp();
    string s;
    int n;
    cin >> n;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    return 0;
}