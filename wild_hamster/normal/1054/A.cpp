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
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
int a[1005000];
vector<int> f;
int Abs(int x) {
    return (x>0?x:-x);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    //cout << (Abs(z-x) + Abs(y-x)) * t2 + 3*t3 << " " << Abs(y-x)*t1 << endl;
    if ((Abs(z-x) + Abs(y-x)) * t2 + 3*t3 <= Abs(y-x)*t1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}