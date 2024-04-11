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
ll n,i,j,k,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz,l;
pii segments[300500];
ll ps[300500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> v >> l >> r;
    v = -v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segments[i+1].X, &segments[i+1].Y);
        ps[i+1] = ps[i] + segments[i+1].Y - segments[i+1].X;
    }
    ps[n+2] = ps[n+1] = ps[n];
    segments[0].X = segments[0].Y = -1;
    segments[n+1].X = segments[n+1].Y = MOD;
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        long double diffx = l-x;
        long double diffy = r-x;
        diffx *= 1.*y/(y+v);
        diffy *= 1.*y/(y+v);
        long double newx = x + diffx;
        long double newy = x + diffy;
        //cout << newx << " " << newy << endl;
        ll posx = upper_bound(segments, segments+n+2, mp((int)newx, MOD)) - segments - 1;
        ll posy = upper_bound(segments, segments+n+2, mp((int)newy, MOD)) - segments - 1;
        //cout << posx << " " << posy << endl;
        long double ans = newy - newx;
        if (newx >= segments[posx].X && newx <= segments[posx].Y)
            ans -= segments[posx].Y - newx;
        if (newy >= segments[posy].X && newy <= segments[posy].Y)
            ans -= newy - segments[posy].X;
        else
            posy++;
        //if (posy > posx || (newx >= segments[posx].X && newx <= segments[posx].Y &&
        //    newy >= segments[posy].X && newy <= segments[posy].Y))
            ans -= ps[posy-1] - ps[posx];
        ans *= 1.*(y+v)/y;
        ans = r-l-ans;
        printf("%.12f\n", (double)ans);
    }
    return 0;
}