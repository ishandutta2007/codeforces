#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll b[100500], a[1000500];
string s;
vector<ll> f;
ll find_level(ll x) {
    ll ans = -1;
    while (x) {
        x /= 2;
        ans++;
    }
    return ans;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> q;
    while (q--) {
        ll test;
        cin >> test;
        if (test == 1) {
            cin >> x >> y;
            y = -y;
            ll lvl = find_level(x);
            a[lvl] += y;
            a[lvl] %= (1LL<<lvl);
            while (a[lvl] < 0) {
                a[lvl] += (1LL<<lvl);
            }
        } else
        if (test == 2) {
            cin >> x >> y;
            y = -y;
            ll lvl = find_level(x);
            y %= (1LL<<lvl);
            if (y < 0) {
                y += (1LL<<lvl);
            }
            for (; lvl < 61; lvl++) {
                a[lvl] += y;
                a[lvl] %= (1LL<<lvl);
                while (a[lvl] < 0) {
                    a[lvl] += (1LL<<lvl);
                }
                y *= 2;
            }
        } else {
            cin >> x;
            ll lvl = find_level(x);
            x -= (1LL<<lvl) + a[lvl];
            x %= (1LL<<lvl);
            if (x < 0) {
                x += (1LL << lvl);
            }
            while (lvl >= 0) {
                cout << (1LL<<lvl) + (x + a[lvl])%(1LL<<lvl) << " ";
                x /= 2;
                lvl--;
            }
            cout << endl;

        }
        /*for (int i = 0; i < 10; i++)
            cout << a[i] << " ";
        cout << endl;*/
    }
    return 0;
}