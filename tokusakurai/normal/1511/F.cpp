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
    int N, M; cin >> N >> M;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    Matrix<mint> A(N*20+1, N*20+1);

    rep(i, N) rep2(j, 1, sz(S[i])-1) rep(k, j+1){
        int p = 20*i+5*(j-1)+k+1;

        if(k >= 1){
            if(j == 1){
                int np = 0;
                A[np][p]++;
            }
            else{
                int ni = i, nj = j-1, nk = k-1;
                int np = 20*ni+5*(nj-1)+nk+1;
                A[np][p]++;
            }
        }
        else{
            rep(l, N){
                if(sz(S[l]) < j){
                    if(S[l] == S[i].substr(sz(S[i])-j, sz(S[l]))){
                        int ni = i, nj = j-1, nk = sz(S[l])-1;
                        int np = 20*ni+5*(nj-1)+nk+1;
                        A[np][p]++;
                    }
                }
                else if(sz(S[l]) == j){
                    if(S[l] == S[i].substr(sz(S[i])-j)){
                        if(j > 1){
                            int ni = i, nj = j-1, nk = j-1;
                            int np = 20*ni+5*(nj-1)+nk+1;
                            A[np][p]++;
                        }
                        else{
                            int np = 0;
                            A[np][p]++;
                        }
                    }
                }
                else{
                    if(S[l].substr(0, j) == S[i].substr(sz(S[i])-j)){
                        int ni = l, nj = sz(S[l])-1, nk = j-1;
                        int np = 20*ni+5*(nj-1)+nk+1;
                        A[np][p]++;
                    }
                }
            }
        }
    }

    rep(i, N) rep(j, N){
        int p = 0;

        if(sz(S[i]) < sz(S[j])){
            if(S[i] == S[j].substr(0, sz(S[i]))){
                int ni = j, nj = sz(S[j])-1, nk = sz(S[i])-1;
                int np = 20*ni+5*(nj-1)+nk+1;
                A[np][p]++;
            }
        }
        else if(sz(S[i]) == sz(S[j])){
            if(S[i] == S[j]){
                if(sz(S[i]) == 1){
                    int np = 0;
                    A[np][p]++;
                }
                else{
                    int ni = i, nj = sz(S[i])-1, nk = sz(S[j])-1;
                    int np = 20*ni+5*(nj-1)+nk+1;
                    A[np][p]++;
                }
            }
        }
        else{
            if(S[i].substr(0, sz(S[j])) == S[j]){
                int ni = i, nj = sz(S[i])-1, nk = sz(S[j])-1;
                int np = 20*ni+5*(nj-1)+nk+1;
                A[np][p]++;
            }
        }
    }

    Matrix<mint> x(N*20+1, 1);
    x[0][0] = 1;

    A = A.pow(M), A *= x;
    cout << A[0][0] << '\n';
}