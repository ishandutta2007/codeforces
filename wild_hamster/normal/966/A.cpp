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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
set<ll> lifts;
set<ll> elevators;
ll Abs(ll x) {
    return (x>0?x:-x);
}
int main() {
    //freopen("input.txt","r",stdin);
    ll n,m,cl,ce,v;
    cin >> n >> m >> cl >> ce >> v;
    for (int i = 0; i < cl; i++) {
        int x;
        scanf("%d", &x);
        lifts.insert(x);
    }
    for (int i = 0; i < ce; i++) {
        int x;
        scanf("%d", &x);
        elevators.insert(x);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&y1, &x1, &y2, &x2);
        ll elevspeed = (y1==y2? 0 : (Abs(y2-y1)-1)/v+1);
        if (y1==y2) {
            cout << Abs(x2-x1) << endl;
            continue;
        }
        ll ans = 5*(n+m);
        {
            auto itr = lifts.upper_bound(x1);
            if (itr != lifts.end()) {
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + Abs(y2-y1));
            }
            if (itr != lifts.begin()) {
                itr--;
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + Abs(y2-y1));
            }
        }

        {
            auto itr = lifts.upper_bound(x2);
            if (itr != lifts.end()) {
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + Abs(y2-y1));
            }
            if (itr != lifts.begin()) {
                itr--;
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + Abs(y2-y1));
            }
        }

        {
            auto itr = elevators.upper_bound(x1);
            if (itr != elevators.end()) {
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + elevspeed);
            }
            if (itr != elevators.begin()) {
                itr--;
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + elevspeed);
            }
        }

        {
            auto itr = elevators.upper_bound(x2);
            if (itr != elevators.end()) {
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + elevspeed);
            }
            if (itr != elevators.begin()) {
                itr--;
                ans = min(ans, Abs((*itr) - x1) + Abs((*itr)-x2) + elevspeed);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}