#define _USE_MATH_DEFINES
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

constexpr ll MOD = 1e6+3;

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

int gauss(vector<vector<Zp>>& A, vector<Zp>& ans, int m) {
    Vi col;
    ans.assign(m, 0);
    rep(i, 0, sz(A)) {
        int c = 0;
        while (c <= m && !A[i][c].x) c++;
        if (c >= m) {
            if (c == m) return 0;
            continue;
        }
        rep(k, i+1, sz(A)) {
            auto mult = A[k][c] / A[i][c];
            rep(j, 0, m+1) A[k][j] -= A[i][j]*mult;
        }
        swap(A[i], A[sz(col)]);
        col.pb(c);
    }
    for (int i = sz(col); i--;) {
        ans[col[i]] = A[i][m] / A[i][col[i]];
        rep(k, 0, i) A[k][m] -= ans[col[i]] * A[k][col[i]];
    }
    return sz(col) < m ? 2 : 1;
}

void run() {
    vector<vector<Zp>> mat(20, vector<Zp>(12));

    rep(i, 0, sz(mat)) {
        Zp p = 1;
        rep(j, 0, 11) {
            mat[i][j] = p;
            p *= i;
        }

        cout << "? " << i << endl;
        int k; cin >> k;
        if (k < 0) exit(0);
        mat[i].back() = k;
    }

    vector<Zp> ans;
    gauss(mat, ans, 11);

    rep(i, 0, MOD) {
        Zp val = 0, p = 1;
        rep(j, 0, 11) {
            val += ans[j]*p;
            p *= i;
        }

        if (val.x == 0) {
            cout << "! " << i << endl;
            return;
        }
    }

    cout << "! -1" << endl;
}