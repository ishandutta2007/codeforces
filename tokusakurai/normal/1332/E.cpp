#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
//const int MOD = 1000000007;
const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<int mod>
struct Mod_Int{
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mod_Int &operator += (const Mod_Int &p){
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator -= (const Mod_Int &p){
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator *= (const Mod_Int &p){
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator /= (const Mod_Int &p){
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator ++ () {return *this += Mod_Int(1);}

    Mod_Int operator ++ (int){
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator -- () {return *this -= Mod_Int(1);}

    Mod_Int operator -- (int){
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator - () const {return Mod_Int(-x);}

    Mod_Int operator + (const Mod_Int &p) const {return Mod_Int(*this) += p;}

    Mod_Int operator - (const Mod_Int &p) const {return Mod_Int(*this) -= p;}

    Mod_Int operator * (const Mod_Int &p) const {return Mod_Int(*this) *= p;}

    Mod_Int operator / (const Mod_Int &p) const {return Mod_Int(*this) /= p;}

    bool operator == (const Mod_Int &p) const {return x == p.x;}

    bool operator != (const Mod_Int &p) const {return x != p.x;}

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod-2);
    }

    Mod_Int pow(ll k) const{
        Mod_Int now = *this, ret = 1;
        for(; k; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Mod_Int &p){
        ll a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template<typename T>
struct Matrix{
    vector<vector<T>> A;

    Matrix(int n, int m) : A(n, vector<T>(m, 0)) {} //+

    int height() const {return sz(A);}

    int width() const {return sz(A.front());}

    inline const vector<T> &operator [] (int k) const {return A[k];}

    inline vector<T> &operator [] (int k) {return A[k];}

    static Matrix I(int l){
        Matrix ret(l, l);
        rep(i, l) ret[i][i] = 1; //*
        return ret;
    }

    Matrix &operator *= (const Matrix &B){
        int n = height(), m = width(), p = B.width();
        assert(m == B.height());
        Matrix tmp(n, p);
        rep(i, n){
            rep(k, m){
                rep(j, p) tmp.A[i][j] += A[i][k]*B[k][j];
            }
        }
        swap(A, tmp.A);
        return *this;
    }

    Matrix operator * (const Matrix &B) const {return Matrix(*this) *= B;}

    Matrix pow(ll k) const{
        int n = height(), m = width();
        assert(n == m);
        Matrix now = *this, ret = I(n);
        while(k){
            if(k&1) ret *= now;
            now *= now, k >>= 1;
        }
        return ret;
    }

    bool eq(const T &a, const T &b) const{
        return a == b;
        //return abs(a-b) <= EPS;
    }

    pair<int, T> normalize(){
        int n = height(), m = width(), check = 0, rank = 0;
        T det = 1;
        rep(j, m){
            int pivot = check;
            rep2(i, check, n-1){
                if(A[i][j] != 0) pivot = i;
                //if(abs(A[i][j]) > abs(A[pivot][j])) pivot = i;
            }
            if(check != pivot) det *= T(-1);
            swap(A[check], A[pivot]);
            if(eq(A[check][j], 0)) {det = T(0); continue;}
            rank++;
            det *= A[check][j];
            rep2(k, j+1, m-1) A[check][k] /= A[check][j];
            A[check][j] = 1;
            rep(i, n){
                if(i == check) continue;
                rep2(k, j+1, m-1) A[i][k] -= A[i][j]*A[check][k];
                A[i][j] = 0;
            }
            if(++check == n) break;
        }
        return make_pair(rank, det);
    }

    vector<vector<T>> Gausiann_elimination(const vector<T> &b){
        int n = height(), m = width();
        assert(sz(b) == n);
        rep(i, n) A[i].pb(b[i]);
        normalize();
        vector<vector<T>> ret;
        vector<int> p(n, m+1);
        vector<bool> is_zero(m, true);
        rep(i, n){
            rep(j, m+1){
                if(!eq(A[i][j], 0)) {p[i] = j; break;}
            }
            if(p[i] < m) is_zero[p[i]] = false;
            if(p[i] == m) return ret;
        }
        vector<T> basis(m, 0);
        rep(i, n){
            if(p[i] < m) basis[p[i]] = A[i][m];
        }
        ret.pb(basis);
        rep(j, m){
            if(!is_zero[j]) continue;
            basis[j] = 1;
            rep(i, n){
                if(p[i] < m) basis[p[i]] = -A[i][j];
            }
            ret.pb(basis), basis[j] = 0;
        }
        return ret;
    }
};

int main(){
    ll N, M, L, R;
    cin >> N >> M >> L >> R;

    mint x = (R-L+1)/2, y = x;

    if(L%2 == 0 && R%2 == 0) x++;
    if(L%2 == 1 && R%2 == 1) y++;

    N *= M;
    if(N&1){
        cout << (x+y).pow(N) << '\n';
        return 0;
    }

    Matrix<mint> A(2, 2), X(2, 1);
    A[0][0] = y, A[0][1] = x, A[1][0] = x, A[1][1] = y;
    X[0][0] = 1, X[1][0] = 0;

    A = A.pow(N);
    A *= X;
    cout << A[0][0] << '\n';
}