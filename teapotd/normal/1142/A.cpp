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

ll n, k, a, b;
ll x = INT64_MAX, y = -1;

ll gcd(ll i, ll j) {
    while (j) {
        i %= j;
        swap(i, j);
    }
    return i;
}

void check(ll s1, ll s2) {
    if (s2 <= s1) s2 += n*k;
    ll z = n*k / gcd(s2-s1, n*k);
    x = min(x, z);
    y = max(y, z);
}

void run() {
    cin >> n >> k >> a >> b;
    rep(arc, 0, n) {
        check(a, arc*k + b);
        check(a, (arc+1)*k - b);
        check(k-a, arc*k + b);
        check(k-a, (arc+1)*k - b);
    }
    cout << x << ' ' << y << '\n';
}