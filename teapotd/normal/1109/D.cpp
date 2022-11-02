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

constexpr ll MOD = 1e9+7;

struct Zp {
    ll x;
    Zp(ll a = 0) {
        if (a < 0) a = a%MOD + MOD;
        else if (a >= MOD*2) a %= MOD;
        else if (a >= MOD) a -= MOD;
        x = a;
    }

    Zp operator+(Zp r) const{ return x+r.x; }
    Zp operator-(Zp r) const{ return x-r.x+MOD; }
    Zp operator*(Zp r) const{ return x*r.x; }
    Zp operator/(Zp r) const{return x*r.inv().x;}
    Zp operator-()     const{ return MOD-x; }
    Zp inv() const { return pow(MOD-2); }

    Zp pow(ll e) const {
        if (e < 0) return inv().pow(-e);
        Zp t = 1, m = *this;
        while (e) {
            if (e & 1) t = t*m;
            e >>= 1; m = m*m;
        }
        return t;
    }

    #define OP(c) Zp& operator c##=(Zp r){ \
        return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
};

vector<Zp> fact;

Zp chooseOrdered(int a, int b) { return fact[a] / fact[a-b]; }
Zp choose(int a, int b) { return fact[a] / (fact[b] * fact[a-b]); }
Zp cayley(int a, int b) { return Zp(a).pow(a-b-1) * b; }

void run() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    fact.resize(max(n, m)+1, 1);
    rep(i, 2, sz(fact)) fact[i] = fact[i-1] * i;

    Zp ans = 0;
    rep(i, 1, min(n, m+1)) ans += chooseOrdered(n-2, i-1) * cayley(n, i+1) * choose(m-1, i-1) * Zp(m).pow(n-i-1);

    cout << ans.x << endl;
}