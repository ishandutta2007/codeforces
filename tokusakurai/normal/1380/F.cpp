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

template<typename Monoid>
struct Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;
    
    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = sz(v);
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1);
        copy(all(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
    
    void change(int i, const Monoid &x){
        seg[i += n] = x;
        while(i >>= 1){
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }
 
    Monoid query(int l, int r) const{
        Monoid L = e1, R = e1;
        l += n, r += n;
        while(l < r){
            if(l&1) L = f(L, seg[l++]);
            if(r&1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }
 
    Monoid operator [] (int i) const {return seg[n+i];}
 
    template<typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) const{
        while(i < n){
            Monoid nxt = type? f(seg[2*i+type], M) : f(M, seg[2*i+type]);
            if(check(nxt, x)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check, const Monoid &x) const{
        Monoid L = e1;
        int a = l+n, b = n+n;
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, seg[a]);
                if(check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check, const Monoid &x) const{
        Monoid R = e1;
        int a = n, b = r+n;
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

int main(){
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<int> A(N);
    rep(i, N) A[i] = S[i]-'0';

    auto f = [](vector<mint> a, vector<mint> b){
        vector<mint> ret(4);
        ret[0] = a[0]*b[0]+a[2]*b[1];
        ret[1] = a[1]*b[0]+a[3]*b[1];
        ret[2] = a[0]*b[2]+a[2]*b[3];
        ret[3] = a[1]*b[2]+a[3]*b[3];
        return ret;
    };
    vector<mint> I(4);
    I[0] = 1, I[1] = 0, I[2] = 0, I[3] = 1;

    vector<vector<mint>> v;
    vector<mint> tmp(4, 0);
    tmp[2] = 1;
    rep(i, N){
        tmp[0] = A[i]+1;
        if(i > 0 && A[i-1] == 1) tmp[1] = 9-A[i];
        else tmp[1] = 0;
        v.pb(tmp);
    }

    Segment_Tree<vector<mint>> seg(v, f, I);

    while(Q--){
        int x, d; cin >> x >> d; x--;

        if(A[x] != d){
            if(x+1 < N && A[x] == 1 && d != 1){
                tmp[0] = A[x+1]+1, tmp[1] = 0;
                seg.change(x+1, tmp);
            }

            A[x] = d;

            tmp[0] = d+1;
            if(x > 0 && A[x-1] == 1) tmp[1] = 9-d;
            else tmp[1] = 0;
            seg.change(x, tmp);

            if(x+1 < N && d == 1){
                tmp[0] = A[x+1]+1, tmp[1] = 9-A[x+1];
                seg.change(x+1, tmp);
            }
        }

        vector<mint> B = seg.query(0, N);
        cout << B[0] << '\n';
    }
}