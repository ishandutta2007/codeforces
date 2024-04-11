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
struct F2_Matrix{
    vector<T> A;

    F2_Matrix(int n) : A(n) {}

    int height() const {return sz(A);}

    int width() const {return sz(A.front());}

    inline const T &operator [] (int k) const {return A[k];}

    inline T &operator [] (int k) {return A[k];}

    int normalize(){
        int n = height(), m = width(), check = 0, rank = 0;
        rep(j, m){
            int pivot = check;
            rep2(i, check, n-1){
                if(A[i][j]) pivot = i;
            }
            swap(A[check], A[pivot]);
            if(!A[check][j]) continue;
            rank++;
            rep(i, n){
                if(i == check || !A[i][j]) continue;
                A[i] ^= A[check];
            }
            if(++check == n) break;
        }
        return rank;
    }
};

template<typename T>
void Fast_Zeta_Transform(vector<T> &f, bool upper){
    int n = sz(f);
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        rep(j, n){
            if(!(j&i)){
                if(upper) f[j] += f[j|i];
                else f[j|i] += f[j];
            }
        }
    }
}

template<typename T>
void Fast_Mobius_Transform(vector<T> &f, bool upper){
    int n = sz(f);
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        rep(j, n){
            if(!(j&i)){
                if(upper) f[j] -= f[j|i];
                else f[j|i] -= f[j];
            }
        }
    }
}

template<typename T>
void Fast_Hadamard_Transform(vector<T> &f, bool inverse = false){
    int n = sz(f);
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        rep(j, n){
            if(!(j&i)){
                T x = f[j], y = f[j|i];
                f[j] = x+y, f[j|i] = x-y;
            }
        }
    }
    if(inverse) each(e, f) e /= n;
}

int main(){
    int N, M;
    cin >> N >> M;

    F2_Matrix<bitset<35>> A(N);
    rep(i, N){
        ll a; cin >> a;
        A[i] = a;
    }
    
    int K = A.normalize();
    mint base = mint(2).pow(N-K);

    if(K <= 22){
        vector<mint> ans(M+1, 0);
        rep(j, 1<<K){
            bitset<35> b;
            rep(k, K){
                if(j&(1<<k)) b ^= A[k];
            }
            ans[b.count()]++;
        }
        each(e, ans) cout << e*base << ' ';
        cout << '\n';
        return 0;
    }
    
    vector<int> id(M, 0), c(K, 0);
    rep(i, K){
        int f = -1;
        rep(j, M){
            if(A[i][j]) {f = j; break;}
        }
        id[f] = -1;
    }

    int n = 0;
    rep(i, M){
        if(id[i] != -1) id[i] = n++;
    }

    rep(i, K){
        rep(j, M){
            if(A[i][j] && id[j] != -1) c[i] |= 1<<id[j];
        }
    }

    int L = K/2, R = K-L;
    vector<vector<mint>> table1(L+1, vector<mint>(1<<n, 0)), table2(R+1, vector<mint>(1<<n, 0));
    
    rep(i, 1<<L){
        int res = 0;
        rep(j, L){
            if(i&(1<<j)) res ^= c[j];
        }
        table1[__builtin_popcount(i)][res]++;
    }

    rep(i, 1<<R){
        int res = 0;
        rep(j, R){
            if(i&(1<<j)) res ^= c[L+j];
        }
        table2[__builtin_popcount(i)][res]++;
    }
    
    vector<mint> ans(M+1, 0);
    rep(i, L+1) Fast_Hadamard_Transform(table1[i]);
    rep(i, R+1) Fast_Hadamard_Transform(table2[i]);

    rep(i, L+1){
        rep(j, R+1){
            vector<mint> tmp(1<<n, 0);
            rep(k, 1<<n) tmp[k] = table1[i][k]*table2[j][k];
            Fast_Hadamard_Transform(tmp);
            rep(k, 1<<n){
                ans[__builtin_popcount(k)+i+j] += tmp[k];
            }
        }
    }

    mint inv = mint(1<<n).inverse();
    each(e, ans) cout << e*inv*base << ' ';
    cout << '\n';
}