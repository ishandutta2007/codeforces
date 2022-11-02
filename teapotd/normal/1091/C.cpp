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

int n;
vector<ll> ans;

void check(int d) {
    ll to = n/d-1;
    ll a = to*(to+1) / 2;
    ans.pb(a*d+to+1);
}

void run() {
    cin >> n;

    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            check(i);
            if (n/i != i) check(n/i);
        }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());

    each(a, ans) cout << a << ' ';
    cout << endl;
}