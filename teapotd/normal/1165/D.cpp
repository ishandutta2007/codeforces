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
#define mp make_pair/////////////////////////////////////////////
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

constexpr int MAX_P = 1e6+5;
Vi factor(MAX_P+1);

void sieve() {
    for (int i = 2; i*i <= MAX_P; i++)
        if (!factor[i])
            for (int j = i*i; j <= MAX_P; j += i)
                if (!factor[j])
                    factor[j] = i;

    rep(i,0,MAX_P+1) if (!factor[i]) factor[i]=i;
}

vector<Pii> factorize(ll n) {
    vector<Pii> ret;
    while (n > 1) {
        int f = factor[n];
        if (ret.empty() || ret.back().x != f)
            ret.pb({ f, 1 });
        else
            ret.back().y++;
        n /= f;
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<ll> divs(n);
    each(d, divs) cin >> d;
    sort(all(divs));

    Vi primes(1e6+5);

    each(d, divs) {
        each(f, factorize(d)) {
            primes[f.x] = max(primes[f.x], f.y);
        }
    }

    ll full = 1;
    bool ans = 1;

    rep(p, 0, sz(primes)) {
        rep(i, 0, primes[p]) {
            full *= p;
            if (full > ll(1e12+500)) {
                ans = 0;
                break;
            }
        }
    }

    if (full == divs.back()) {
        full *= divs[0];
    }

    if (ans) {
        vector<ll> wanted;

        for (ll d = 2; d*d <= full; d++) {
            if (full%d == 0) {
                wanted.pb(d);
                if (d*d != full) wanted.pb(full/d);
            }
        }

        sort(all(wanted));
        ans = (wanted == divs);
    }

    if (ans) {
        cout << full << '\n';
    } else {
        cout << -1 << '\n';
    }
}

void run() {
    sieve();
    int t; cin >> t;
    while (t--) solve();
}