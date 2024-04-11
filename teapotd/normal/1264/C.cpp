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

constexpr int MOD = 998244353;

ll modPow(ll a, ll e, ll m) { // a^e mod m
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x; // Contained value, in range [0;MOD-1]
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { \
            x = x d; return *this; } \
        Zp operator c(Zp r) const { \
            Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; } // For deb()
};

//#define Zp double

void run() {
    int n, q; cin >> n >> q;

    vector<Zp> prob(n);
    rep(i, 0, n) {
        int k; cin >> k;
        prob[i] = Zp(k) / 100;
    }

    vector<Zp> prefMul = {1}, prefMul2 = {1};
    vector<Zp> prefProb = {0}, prefAdd = {0};

    rep(i, 0, n) {
        prefMul.pb(prefMul[i] * prob[i]);
        prefMul2.pb(prefMul[i] * (Zp(1)-prob[i]));
        prefProb.pb(prefProb[i] + prefMul2[i+1]);
        prefAdd.pb(prefAdd[i] + prefMul2[i+1] * (i+1));
    }

    auto get = [&](int begin, int end) {
        Zp mul = (prefProb[end] - prefProb[begin]) / prefMul[begin];
        Zp add = (prefAdd[end] - prefAdd[begin]) / prefMul[begin];
        add -= mul * begin;
        add += (prefMul[end] / prefMul[begin]) * (end-begin);

        //deb(begin, end, mul, add);

        Zp e = add / (Zp(1)-mul);
        return e;
    };

    Zp ans = get(0, n);
    set<int> checks;
    checks.insert(0);
    checks.insert(n);

    //deb(prob, prefMul, prefMul2, prefProb, prefAdd, ans);

    rep(i, 0, q) {
        int k; cin >> k;
        k--;

        if (checks.count(k)) {
            auto it = checks.erase(checks.find(k));
            ans -= get(*prev(it), k);
            ans -= get(k, *it);
            ans += get(*prev(it), *it);
        } else {
            auto it = checks.insert(k).x;
            ans -= get(*prev(it), *next(it));
            ans += get(*prev(it), *it);
            ans += get(*it, *next(it));
        }

        cout << ans.x << '\n';
        //cout << ans << '\n';
    }
}