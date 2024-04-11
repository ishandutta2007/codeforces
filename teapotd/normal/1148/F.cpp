#define _USE_MATH_DEFINES
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

void run() {
    int n; cin >> n;
    vector<ll> val(n), mask(n);
    ll sum = 0;

    rep(i, 0, n) {
        cin >> val[i] >> mask[i];
        sum += val[i];
    }

    if (sum < 0) {
        sum *= -1;
        each(e, val) e *= -1;
    }

    ll ans = 0;

    rep(b, 0, 62) {
        ll m = 1LL << b;
        ll part = 0;

        rep(i, 0, n) if (mask[i] & m) {
            if ((mask[i] & ~m) == 0) {
                part += val[i];
            }
        }

        if (part > 0) {
            ans |= m;
            rep(i, 0, n) if (mask[i] & m) {
                mask[i] &= ~m;
                sum -= val[i]*2;
                val[i] *= -1;
            }
        } else {
            rep(i, 0, n) if (mask[i] & m) {
                mask[i] &= ~m;
            }
        }
    }

    deb(sum);
    cout << ans << '\n';
}