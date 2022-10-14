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
multiset<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> m;
        auto Abs = [](ll x) {return x>0?x:-x;};
        f.insert(Abs(m-a[i]));
        z += Abs(m-a[i]);
    }
    for (int i = 0; i < x+y; i++) {
        auto itr = f.end();
        itr--;
        auto val = *itr;
        f.erase(itr);
        f.insert(max(0LL, val-1));
    }
    ll ans = 0;
    for (auto itr = f.begin(); itr != f.end(); itr++) {
        ans += (*itr)*(*itr);
    }
    if ((z-x-y)%2 && ans == 0)
        ans = 1;
    cout << ans << endl;
    return 0;
}