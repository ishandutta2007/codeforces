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

const double pi = acos(-1.0);

template<typename T>
struct Fast_Foulier_Transform{
    using comp = complex<double>;
    vector<comp> r, ir;

    Fast_Foulier_Transform(){
        r.resize(30), ir.resize(30);
        for(int i = 0; i < 30; i++){
            r[i] = -polar(1.0, pi/(1<<(i+1)));
            ir[i] = -polar(1.0, -pi/(1<<(i+1)));
        }
    };

    vector<comp> to_comp(const vector<T> &a) const{
        vector<comp> ret(a.size());
        for(int i = 0; i < (int)a.size(); i++) ret[i] = comp(a[i], 0.0);
        return ret;
    }

    vector<T> to_T(const vector<comp> &a) const{
        vector<T> ret(a.size(), 0);
        for(int i = 0; i < (int)a.size(); i++) ret[i] = a[i].real()+0.1;
        //for(int i = 0; i < (int)a.size(); i++) ret[i] = a[i].real();
        return ret;
    }

    void fft(vector<comp> &a, int n) const{
        assert((n&(n-1)) == 0);
        a.resize(n);
        for(int k = n; k >>= 1;){
            comp w = 1;
            for(int s = 0, t = 0; s < n; s += 2*k){
                for(int i = s, j = s+k; i < s+k; i++, j++){
                    comp x = a[i], y = w*a[j];
                    a[i] = x+y, a[j] = x-y;
                }
                w *= r[__builtin_ctz(++t)];
            }
        }
    }

    void ifft(vector<comp> &a, int n) const{
        assert((n&(n-1)) == 0);
        a.resize(n);
        for(int k = 1; k < n; k <<= 1){
            comp w = 1;
            for(int s = 0, t = 0; s < n; s += 2*k){
                for(int i = s, j = s+k; i < s+k; i++, j++){
                    comp x = a[i], y = a[j];
                    a[i] = x+y, a[j] = w*(x-y);
                }
                w *= ir[__builtin_ctz(++t)];
            }
        }
        for(auto &e: a) e /= n;
    }

    vector<T> convolve(const vector<T> &a, const vector<T> &b) const{
        int k = (int)a.size()+(int)b.size()-1, n = 1;
        while(n < k) n <<= 1;
        vector<comp> A = to_comp(a), B = to_comp(b);
        fft(A, n), fft(B, n);
        for(int i = 0; i < n; i++) A[i] *= B[i];
        ifft(A, n);
        vector<T> c = to_T(A);
        c.resize(k);
        return c;
    }
};

int main(){
    int N, x, y; cin >> N >> x >> y;

    vector<int> a(N+1);
    rep(i, N+1) cin >> a[i];

    vector<int> f(x+1, 0), g(x+1, 0);
    rep(i, N+1){
        f[a[i]]++, g[x-a[i]]++;
    }

    Fast_Foulier_Transform<int> FFT;
    vector<int> h = FFT.convolve(f, g);

    int MAX = 1000000;
    vector<int> ans(MAX+1, -1);
    rep2(i, 1, x){
        if(h[x+i] == 0) continue;
        int t = 2*(i+y);
        for(int j = t; j <= MAX; j += t) ans[j] = t;
    }

    int Q; cin >> Q;

    rep(i, Q){
        int l; cin >> l;
        cout << ans[l] << (i == Q-1? '\n' : ' ');
    }
}