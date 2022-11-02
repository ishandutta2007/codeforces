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

ll ch2(ll k) { return k*(k-1) / 2; }

ll largest(ll n) {
    ll begin = 0, end = n+10;
    while (begin+1 < end) {
        ll mid = (begin+end) / 2;
        if (ch2(mid) <= n) {
            begin = mid;
        } else {
            end = mid;
        }
    }
    return begin;
}

string solve(ll n) {
    vector<ll> threes;

    while (n > 0) {
        ll cnt = largest(n);
        threes.pb(cnt);
        n -= ch2(cnt);
    }

    string ans;
    ll last = 0;

    each(t, threes) {
        while (last > t) {
            ans += '3';
            last--;
        }
        last = t;
        ans += '1';
    }

    while (last > 0) {
        ans += '3';
        last--;
    }

    ans += '7';
    return ans;
}

void run() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
}