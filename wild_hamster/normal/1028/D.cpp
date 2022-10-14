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
ll n,i,j,k,z,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[400500], b[400500];
char s[10];
set<ll> ASK, BID, dk;
int main() {
    //freopen("input.txt","r",stdin);
    ll ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        scanf("%d",&x);
        ll cur = x;
        ll best_ask = MOD;
        ll best_bid = -MOD;
        if (!ASK.empty()) {
            auto itr = ASK.begin();
            best_ask = *itr;
        }
        if (!BID.empty()) {
            auto itr = BID.end();
            itr--;
            best_bid = *itr;
        }
        //cout << best_ask << " " << best_bid << endl;
        if (s[1] == 'C') {
            if (cur == best_ask) {
                ASK.erase(cur);
            } else
            if (cur == best_bid) {
                BID.erase(cur);
            } else
            if (cur > best_bid && cur < best_ask) {
                ans = ans*2%MOD;
            } else {
                cout << 0 << endl;
                return 0;
            }
            for (auto itr = dk.begin(); itr != dk.end(); itr++) {
                if (*itr > cur)
                    ASK.insert(*itr);
                else if (*itr < cur)
                    BID.insert(*itr);
            }
            dk.clear();
        } else {
            if (cur > best_ask)
                ASK.insert(cur);
            else if (cur < best_bid)
                BID.insert(cur);
            else
                dk.insert(cur);
        }
    }
    int sz = dk.size();
    ans = 1LL*ans*(sz+1)%MOD;
    cout << ans << endl;
    return 0;
}