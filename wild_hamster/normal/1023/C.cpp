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
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,xx, yy,INF, sz, sum;
ll  a[200500];
vector<ll> f;
vector<pii> g;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            f.push_back(i);
        else {
            ll x = f.back();
            g.push_back(mp(x, i));
            f.pop_back();
        }
    }
    for (int i = 0; i < (n-k)/2; i++) {
        a[g[i].X] = 1;
        a[g[i].Y] = 1;
    }
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            cout << s[i];
    cout << endl;
    return 0;
}