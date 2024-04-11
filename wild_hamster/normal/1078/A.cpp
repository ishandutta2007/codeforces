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
ll n,m,k,a[100500],x, ls[105][10500] ,b[105], y, z, l, i, j, p;
vector<ll> v;
ll Abs(ll x) {
    return x>0?x:-x;
}
long double dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
     //freopen("input.txt","r",stdin);
    ll a,b,c,x1,y1,x2,y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    if (a == 0 || b == 0) {
        cout << Abs(x1-x2) + Abs(y1-y2) << endl;
        return 0;
    }
    long double ans = Abs(x1-x2) + Abs(y1-y2);
    long double Ax = 1. * (-c - b*y1) / a;
    long double Ay = 1. * (-c - a*x1) / b;
    long double Bx = 1. * (-c - b*y2) / a;
    long double By = 1. * (-c - a*x2) / b;
    //cout << Ax << " " << Ay << " " << Bx << " " << By << endl;
    ans = min(ans, dist(x1, y1, x1, Ay) + dist(x1, Ay, x2, By) + dist(x2, By, x2, y2));
    ans = min(ans, dist(x1, y1, Ax, y1) + dist(Ax, y1, x2, By) + dist(x2, By, x2, y2));
    ans = min(ans, dist(x1, y1, x1, Ay) + dist(x1, Ay, Bx, y2) + dist(Bx, y2, x2, y2));
    ans = min(ans, dist(x1, y1, Ax, y1) + dist(Ax, y1, Bx, y2) + dist(Bx, y2, x2, y2));
    printf("%.10f\n", (double)ans);
    return 0;
}