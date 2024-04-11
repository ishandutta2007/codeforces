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

constexpr int MOD = 1e9+7;

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

struct Matrix {
    vector<Zp> M;
    int n;

    Matrix(int k) : M(k*k), n(k) {}
    Zp at(int i, int j) const { return M[i*n+j]; }
    Zp& at(int i, int j) { return M[i*n+j]; }

    Matrix operator*(const Matrix& r) const {
        Matrix ret(n);
        rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) ret.at(i, j) += at(i, k) * r.at(k, j);
        return ret;
    }

    Matrix pow(int p) const {
        if (p == 0) {
            Matrix ret(n);
            rep(i, 0, n) ret.at(i, i) = 1;
            return ret;
        }
        if (p == 1) {
            return *this;
        }

        Matrix tmp = pow(p/2);
        tmp = tmp*tmp;
        if (p%2) tmp = tmp * *this;
        return tmp;
    }
};

void run() {
    int n, k; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    int ones = 0;
    each(e, elems) ones += e;

    int zeroes = n-ones;
    int displaced = 0;
    rep(i, 0, zeroes) displaced += elems[i];

    Matrix mat(min(zeroes, ones)+1);
    int allPairs = n*(n-1)/2;

    rep(i, 0, mat.n) {
        int zeroOne = (zeroes-i) * (ones-i);
        int oneZero = i * i;
        int remain = allPairs - zeroOne - oneZero;

        mat.at(i, i) = Zp(remain) / allPairs;
        if (i > 0) mat.at(i, i-1) = Zp(oneZero) / allPairs;
        if (i+1 < mat.n) mat.at(i, i+1) = Zp(zeroOne) / allPairs;
    }

    mat = mat.pow(k);
    cout << mat.at(displaced, 0).x << endl;
}