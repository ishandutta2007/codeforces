#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

void run() {
    int n; cin >> n;
    vector<Pii> obe(n);
    vector<Pii> clues(n);

    each(p, obe) cin >> p.x >> p.y;
    each(c, clues) cin >> c.x >> c.y;

    each(c, clues) {
        int x = obe[0].x + c.x, y = obe[0].y + c.y;

        set<Pii> avail;
        each(c, clues) avail.insert(c);
        bool ok = 1;

        each(p, obe) {
            Pii xd = {x-p.x, y-p.y};

            if (!avail.count(xd)) {
                ok = 0;
                break;
            }
            avail.erase(xd);
        }

        if (ok) {
            cout << x << ' ' << y << endl;
            return;
        }
    }
}