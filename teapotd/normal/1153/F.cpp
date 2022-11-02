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

constexpr int MOD = 998244353;

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
        Zp t = 1, m = *this;
        while (e) {
            if (e & 1) t = t*m;
            e >>= 1; m = m*m;
        }
        return t;
    }
    #define OP(c) Zp& operator c##=(Zp r){ return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
};

int n, k, l;
vector<vector<Zp>> newton;
vector<Zp> fact, pairing;

void run() {
    cin >> n >> k >> l;

    newton.resize(n*2+1, vector<Zp>(n*2+1));
    rep(i, 0, n*2+1) {
        newton[i][0] = 1;
        rep(j, 1, i+1) newton[i][j] = newton[i-1][j] + newton[i-1][j-1];
    }

    fact.resize(n*2+1, 1);
    rep(i, 1, n*2+1) fact[i] = fact[i-1] * i;

    pairing.resize(n*2+1, 0);
    pairing[0] = 1;
    rep(i, 2, n*2+1) pairing[i] = pairing[i-2] * (i-1);

    Zp ans = 0;

    rep(i, 0, n*2+1) {
        int before = i, after = n*2-i;
        rep(over, k, min(before, after)+1) {
            ans += newton[before][over] * newton[after][over] * fact[over] * pairing[before-over] * pairing[after-over];
        }
    }

    ans /= pairing[n*2];
    ans *= l;
    ans /= n*2+1;
    cout << ans.x << endl;
}