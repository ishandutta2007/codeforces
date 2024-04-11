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
#define COL 10
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot;
int main() {
    //freopen("input.txt","r",stdin);
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    if (c == 0 && d > 0 || a == 0 && b*d > 0 || a*c*e < b*d*f)
        cout << "Ron" << endl;
    else
        cout << "Hermione" << endl;
    return 0;
}