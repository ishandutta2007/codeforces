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
const int MOD = 1000000007;
//const int MOD = 998244353;
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

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

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

    Mod_Int inverse() const{
        assert(*this != Mod_Int(0));
        return pow(mod-2);
    }

    Mod_Int pow(long long k) const{
        Mod_Int now = *this, ret = 1;
        for(; k > 0; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Mod_Int &p){
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template<int mod>
struct Combination{
    using T = Mod_Int<mod>;
    vector<T> _fac, _ifac;

    Combination(int n){
        _fac.resize(n+1), _ifac.resize(n+1);
        _fac[0] = 1;
        for(int i = 1; i <= n; i++) _fac[i] = _fac[i-1]*i;
        _ifac[n] = _fac[n].inverse();
        for(int i = n; i >= 1; i--) _ifac[i-1] = _ifac[i]*i;
    }

    T fac(int k) const {return _fac[k];}

    T ifac(int k) const {return _ifac[k];}

    T comb(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k)*ifac(k);
    }

    T comb2(int x, int y) const {return comb(x+y, x);}

    T perm(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k);
    }

    T second_stirling_number(int n, int k) const{ //nk1
        T ret = 0;
        for(int i = 0; i <= k; i++){
            T tmp = comb(k, i)*T(i).pow(n);
            ret += ((k-i)&1)? -tmp : tmp;
        }
        return ret*ifac(k);
    }

    T bell_number(int n, int k) const{ //nk
        if(n == 0) return 1;
        k = min(k, n);
        vector<T> pref(k+1);
        pref[0] = 1;
        for(int i = 1; i <= k; i++){
            if(i&1) pref[i] = pref[i-1]-ifac(i);
            else pref[i] = pref[i-1]+ifac(i);   
        }
        T ret = 0;
        for(int i = 1; i <= k; i++){
            ret += T(i).pow(n)*ifac(i)*pref[k-i];
        }
        return ret;
    }
};

using comb = Combination<MOD>;

template<typename T>
struct Matrix{
    vector<vector<T>> A;

    Matrix(int m, int n) : A(m, vector<T>(n, 0)) {}

    int height() const {return A.size();}

    int width() const {return A.front().size();}

    inline const vector<T> &operator [] (int k) const {return A[k];}

    inline vector<T> &operator [] (int k) {return A[k];}

    static Matrix I(int l){
        Matrix ret(l, l);
        for(int i = 0; i < l; i++) ret[i][i] = 1;
        return ret;
    }

    Matrix &operator *= (const Matrix &B){
        int m = height(), n = width(), p = B.width();
        assert(n == B.height());
        Matrix ret(m, p);
        for(int i = 0; i < m; i++){
            for(int k = 0; k < n; k++){
                for(int j = 0; j < p; j++){
                    ret[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        swap(A, ret.A);
        return *this;
    }

    Matrix operator * (const Matrix &B) const {return Matrix(*this) *= B;}

    Matrix pow(long long k) const{
        int m = height(), n = width();
        assert(m == n);
        Matrix now = *this, ret = I(n);
        for(; k > 0; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    bool eq(const T &a, const T &b) const{
        return a == b;
        //return abs(a-b) <= EPS;
    }

    pair<int, T> row_reduction(vector<T> &b){ //()
        int m = height(), n = width(), check = 0, rank = 0;
        T det = 1;
        assert(b.size() == m);
        for(int j = 0; j < n; j++){
            int pivot = check;
            for(int i = check; i < m; i++){
                if(A[i][j] != 0) pivot = i;
                //if(abs(A[i][j]) > abs(A[pivot][j])) pivot = i; //T
            }
            if(check != pivot) det *= T(-1);
            swap(A[check], A[pivot]), swap(b[check], b[pivot]);
            if(eq(A[check][j], T(0))) {det = T(0); continue;}
            rank++;
            det *= A[check][j];
            for(int k = j+1; k < n; k++) A[check][k] /= A[check][j];
            b[check] /= A[check][j];
            A[check][j] = T(1);
            for(int i = 0; i < m; i++){
                if(i == check) continue;
                for(int k = j+1; k < n; k++) A[i][k] -= A[i][j]*A[check][k];
                b[i] -= A[i][j]*b[check];
                A[i][j] = T(0);
            }
            if(++check == m) break;
        }
        return make_pair(rank, det);
    }

    pair<int, T> row_reduction(){
        vector<T> b(height(), T(0));
        return row_reduction(b);
    }

    vector<vector<T>> Gausiann_elimination(vector<T> b){ //Ax=b1
        int m = height(), n = width();
        row_reduction(b);
        vector<vector<T>> ret;
        vector<int> p(m, n);
        vector<bool> is_zero(n, true);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!eq(A[i][j], T(0))) {p[i] = j; break;}
            }
            if(p[i] < n) is_zero[p[i]] = false;
            else if(!eq(b[i], T(0))) return {};
        }
        vector<T> x(n, T(0));
        for(int i = 0; i < m; i++){
            if(p[i] < n) x[p[i]] = b[i];
        }
        ret.push_back(x);
        for(int j = 0; j < n; j++){
            if(!is_zero[j]) continue;
            x[j] = T(1);
            for(int i = 0; i < m; i++){
                if(p[i] < n) x[p[i]] = -A[i][j];
            }
            ret.push_back(x), x[j] = T(0);
        }
        return ret;
    }
};

int main(){
    ll N; int K; cin >> N >> K;

    using mat = Matrix<mint>;
    comb C(K);

    mat A(2*K+3, 2*K+3);

    rep2(i, 0, K){
        A[i][K+1+i] += 1;
        rep2(j, 0, i){
            A[K+1+i][j] += C.comb(i, j)*mint(2).pow(i-j);
            A[K+1+i][K+1+j] += C.comb(i, j);
        }
    }
    A[2*K+2][2*K+1] = 1, A[2*K+2][2*K+2] = 1;

    mat x(2*K+3, 1);

    x[0][0] = 1;
    rep2(i, 0, K) x[K+1+i][0] = 1;

    A = A.pow(N);
    A *= x;
    cout << A[2*K+2][0] << '\n';
}