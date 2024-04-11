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
ll n,i,j,k,z,m,q,r,timer,l, cnt,v,tot,x,y,xx, yy,INF, sz, sum;
ll a[200500];
ll mx[200500], mn[200500], nxt[200500], prv[200500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    string s;
    string t;
    ll curx = 1, cury = 1;
    for (int i = 0; i < n-1; i++) {
        cout << "? " << curx + 1 << " " << cury << " " << n << " " << n << endl;
        fflush(stdout);
        string ans;
        cin >> ans;
        if (ans == "YES") {
            s.push_back('D');
            curx++;
        } else {
            s.push_back('R');
            cury++;
        }
    }

    curx = n, cury = n;
    for (int i = 0; i < n-1; i++) {
        cout << "? " << 1 << " " << 1 << " " << curx << " " << cury-1 << endl;
        fflush(stdout);
        string ans;
        cin >> ans;
        if (ans == "YES") {
            t.push_back('R');
            cury--;
        } else {
            t.push_back('D');
            curx--;
        }
    }
    reverse(t.begin(), t.end());
    cout << "! " << s << t << endl;
    return 0;
}