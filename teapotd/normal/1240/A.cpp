#define _USE_MATH_DEFINES////////////////////////////////////////
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

ll gcd(ll a, ll b) {
    while (b) {
        a %= b; 
        swap(a, b);
    }
    return a;
}

void solve() {
    int n; cin >> n;
    vector<ll> p(n);

    each(a, p) {
        cin >> a;
        a /= 100;
    }

    ll x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;

    if (x < y) {
        swap(x, y);
        swap(a, b);
    }

    ll lcm = a / gcd(a, b) * b;
    sort(all(p));
    reverse(all(p));

    auto check = [&](int lim) {
        ll ret = 0;
        int used = 0;

        for (ll i = lcm; i <= lim; i += lcm) {
            ret += p[used++] * (x+y);
        }

        for (ll i = a; i <= lim; i += a) {
            if (i % lcm) {
                ret += p[used++] * x;
            }
        }

        for (ll i = b; i <= lim; i += b) {
            if (i % lcm) {
                ret += p[used++] * y;
            }
        }

        return ret >= k;
    };

    int begin = 0, end = n+2;

    while (begin+1 < end) {
        int mid = (begin+end) / 2 - 1;
        if (check(mid)) {
            end = mid+1;
        } else {
            begin = mid+1;
        }
    }

    cout << (begin <= n ? begin : -1) << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}