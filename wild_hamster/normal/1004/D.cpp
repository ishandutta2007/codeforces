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
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans, sz,d;
ll a[1000500], b[1000500];
vector<ll> f;
set<ll> g;
ll Abs(ll x) {
    return x>0?x:-x;
}
void try_arr(ll n, ll m, ll x, ll y) {

    //cout << n << " " << m << " " << x << " " << y << endl;
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    //cout << n << " " << sz << " " << m << " " << x << " " << y << endl;
    for (int i = 0; i <= tot; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[Abs(i-x)+Abs(j-y)]++;
    for (int i = 0; i <= tot; i++)
        if (a[i] != b[i])
            return;
    cout << n << " " << m << endl << x+1 << " " << y+1 << endl;
    exit(0);
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%d", &x);
        a[x]++;
        tot = max(tot, x);
    }
    if (a[0] != 1) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    if (a[tot] == 1) {
        for (int i = 1; i <= tot; i++)
        if (a[i] != i*4) {
            sz = i;
            break;
        }

    }
    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            ll x = i;
            ll y = n/i;
            if (a[tot] > 1) {

                ll posx, posy;
                if (x%2 == 1) {
                    //0, 0, x-1, 0
                    posx = (x-1)/2;
                    posy = tot - (x-1)/2;
                    try_arr(x, y, posx, posy);
                }
                if (y%2 == 1) {
                    //0, 0, 0, y-1
                    posx = tot - (y-1)/2;
                    posy = (y-1)/2;
                    try_arr(x, y, posx, posy);
                }
            } else {
                //0, 0
                try_arr(x, y, sz-1, tot-(sz-1));
                try_arr(x, y, tot-(sz-1), sz-1);
                try_arr(x, y, x-1-(sz-1), tot-(x-1-(sz-1)));
                try_arr(x, y, tot-(y-1-(sz-1)), y-1-(sz-1));
                //x-1, 0
                try_arr(x, y, x-(sz-1), tot-(sz-1));
                try_arr(x, y, x-(tot-(sz-1)), sz-1);
                try_arr(x, y, x-(x-1-(sz-1)), tot-(x-1-(sz-1)));
                try_arr(x, y, x-(tot-(y-1-(sz-1))), y-1-(sz-1));
            }
        }
    }
    cout << -1 << endl;
    return 0;
}