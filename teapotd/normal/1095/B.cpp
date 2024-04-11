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
    Vi elems(n);
    int eMin = INT_MAX, eMax = INT_MIN;

    each(e, elems) {
        cin >> e;
        eMin = min(eMin, e);
        eMax = max(eMax, e);
    }

    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN;

    each(e, elems) {
        if (e != eMin) {
            min1 = min(min1, e);
            max1 = max(max1, e);
        } else {
            eMin = -1;
        }

        if (e != eMax) {
            min2 = min(min2, e);
            max2 = max(max2, e);
        } else {
            eMax = -1;
        }
    }

    cout << min(max1-min1, max2-min2) << endl;
}