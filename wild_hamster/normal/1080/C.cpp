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
ll n,m,k,x, rt[35], y, z, l, i, j, p;
ll a[100500];
ll used[100500], last_move;
ll get(ll x, ll y) {
    return (x * y + 1) / 2;
}
int main() {
     //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> n >> m >> y1 >> x1 >> y2 >> x2 >> y3 >> x3 >> y4 >> x4;
        ll ax = max(x1, x3);
        ll bx = min(x2, x4);
        ll ay = max(y1, y3);
        ll by = min(y2, y4);
        ll white = 0;
        white += get(n, m);
        white += (x2-x1+1)*(y2-y1+1) - (get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1));
        //cout << white << endl;
        white -= get(x4, y4) - get(x3-1, y4) - get(x4, y3-1) + get(x3-1, y3-1);
        //cout << white << endl;
        if (ax <= bx && ay <= by)
        white -= (bx-ax+1)*(by-ay+1) - (get(bx, by) - get(ax-1, by) - get(bx, ay-1) + get(ax-1, ay-1));
        cout << white << " " << n*m-white << endl;
    }
    return 0;
}