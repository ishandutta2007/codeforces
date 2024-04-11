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

constexpr ll MOD = 998244353;

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

int n, k;
Vi elems;

void run() {
    cin >> n >> k;
    elems.resize(n);
    each(e, elems) cin >> e;

    vector<Zp> km1(n+1);
    km1[0] = 1;
    rep(i, 1, n+1) km1[i] = km1[i-1] * (k-1);

    vector<Zp> same(n+1), diff(n+1);
    same[0] = 1;
    same[1] = 0;
    diff[0] = 0;
    diff[1] = 1;

    rep(i, 2, n+1) {
        same[i] = km1[i-1] - same[i-1];
        diff[i] = km1[i-1] - diff[i-1];
    }

    Zp ans = 1;

    rep(i, 0, n) {
        if (i >= 2 && elems[i] == elems[i-2] && elems[i] != -1) {
            ans = 0;
            break;
        }

        if (elems[i] != -1) continue;
        if (i >= 2 && elems[i-2] == -1) continue;

        int j = i;
        while (j+2 < n && elems[j+2] == -1) j += 2;

        int len = (j-i) / 2 + 1;

        if (i-2 < 0 && j+2 >= n) {
            if (len > 0) {
                ans *= km1[len-1] * k;
            }
        } else if (i-2 >= 0 && j+2 < n) {
            int before = elems[i-2], after = elems[j+2];
            if (len > 0) {
                if (before == after) {
                    ans *= same[len+1];
                } else {
                    ans *= diff[len+1];
                }
            } else if (before == after) {
                ans = 0;
                break;
            }
        } else {
            ans *= km1[len];
        }
    }

    cout << ans.x << '\n';
}