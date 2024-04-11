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
#define COL 102
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot;
vector<ll> f;
ll a[205][205];
pii b[10];
int main() {
    //freopen("input.txt","r",stdin);
    for (int i = 0; i < 4; i++)
        cin >> b[i].X >> b[i].Y;

    for (int i = 4; i < 8; i++)
        cin >> b[i].X >> b[i].Y;
    sort(b, b+4);
    sort(b+4, b+8);
    for (int i = b[0].X; i <= b[2].X; i++)
        for (int j = b[0].Y; j <= b[1].Y; j++)
            a[i+COL][j+COL]++;
    ll lowx = b[4].X+COL;
    ll highx = b[7].X+COL;
    ll lowy = b[5].Y+COL;
    ll highy = b[6].Y+COL;
    ll midy = b[4].Y+COL;
    ll midx = b[5].X+COL;
    ll lft = lowy, rgt = highy, curup = midx, curdown = midx;
    while (lft <= rgt) {
        for (int i = lft; i <= rgt; i++) {
            a[curup][i] |= 2;
            a[curdown][i] |= 2;
        }
        curup++;
        curdown--;
        lft++;
        rgt--;
    }
    for (int i = 0; i < 205; i++)
        for (int j = 0; j < 205; j++)
    if (a[i][j] == 3) {
        cout << "YES" << endl;
        return 0;
    }
    /*for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            cout << a[i+COL][j+COL];
            cout << endl;
        }*/
    cout << "NO" << endl;
    return 0;
}