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

constexpr ll MOD = 998244353;

void run() {
    int n; cin >> n;
    string str; cin >> str;

    bool ok = 1;
    each(c, str) if (c != str[0]) {
        ok = 0;
        break;
    }

    if (ok) {
        cout << ll(n+1)*n/2 % MOD << '\n';
        return;
    }

    int firstDif = 0;
    while (firstDif < n && str[firstDif] == str[0]) firstDif++;

    int lastDif = n-1;
    while (lastDif >= 0 && str[lastDif] == str.back()) lastDif--;

    int tail = n-lastDif-1;

    if (str[0] != str.back()) {
        cout << (firstDif+tail+1) % MOD << '\n';
        return;
    }

    cout << ll(firstDif+1)*ll(tail+1) % MOD << '\n';
}