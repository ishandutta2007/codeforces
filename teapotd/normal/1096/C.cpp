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

int gcd(int a, int b) {
    while (b) {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int ang; cin >> ang;
        int up = ang*2, down = 360;

        int g = gcd(up, down);
        up /= g;
        down /= g;

        int ans;

        if (up+1 == down) {
            ans = down*2;
        } else if (up >= down) {
            ans = -1;
        } else {
            ans = down;
        }

        cout << ans << '\n';
    }
}