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
#define PI 3.14159265359
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500];
ll start[1005], en[1005], needed[1005], used[1005];
ll w[200500];
set<pair<pii, ll> > f;
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> start[i] >> en[i] >> needed[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++)
            if (i == start[j])
                f.insert(mp(mp(en[j], needed[j]), j+1));
        ll is_exam = 0;
        for (int j = 0; j < m; j++)
        if (i == en[j]) {
            is_exam = 1;
            if (!used[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (!is_exam) {
            if (f.empty())
                continue;
            auto itr = f.begin();
            ll x = (*itr).X.X;
            ll y = (*itr).X.Y;
            ll z = (*itr).Y;
            //cout << i << " " << x << " " << y << " " << z << endl;
            a[i] = z;
            y--;
            f.erase(itr);
            if (y > 0) {
                f.insert(mp(mp(x, y), z));
            } else {
                used[z-1] = 1;
            }
        } else {
            a[i] = m+1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}