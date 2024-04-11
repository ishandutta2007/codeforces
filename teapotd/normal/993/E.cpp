#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

using Vfft = vector<complex<long double>>;
Vfft bases;

void initFFT(int n) { // n must be power of 2
    bases.resize(n+1, 1);
    auto b = exp(complex<long double>(0, 2*M_PI/n));
    rep(i, 1, n+1) bases[i] = b * bases[i-1];
}

template<int dir> // 1 for DFT, -1 for inverse
void fft(Vfft& buf) {
    int n = sz(buf), bits = 31-__builtin_clz(n);
    int i = (dir > 0 ? 0 : bits-1);

    for (; i >= 0 && i < bits; i += dir) {
        int shift = 1 << (bits-i-1);

        rep(j, 0, 1 << i) rep(k, 0, shift) {
            int a = (j << (bits-i)) | k;
            int b = a | shift;
            auto v1 = buf[a], v2 = buf[b];
            auto base = bases[(dir*(k<<i)) & (n-1)];

            if (dir > 0) {
                buf[b] = (v1 - v2) * base;
            } else {
                v2 = v2*base;
                buf[b] = v1 - v2;
            }
            buf[a] = v1 + v2;
        }
    }

    if (dir < 0) {
        long double y = 1;
        y /= n;
        each(x, buf) x = x*y;
    }
}

// ---

struct Poly {
    using T = long double; // Set appropriate type
    vector<T> C;

    Poly(int n = 0) { C.resize(n); }

    // Cut off trailing zeroes
    void reduce() {
        // Change here `.x` if not using Zp
        while (!C.empty() && fabs(C.back()) <= 1e-9)
            C.pop_back();
    }

    // Evaluate polynomial at x; time: O(n)
    T eval(T x) {
        T n = 0, y = 1;
        each(a, C) n += a*y, y *= x;
        return n;
    }

    // Add polynomial; time: O(n)
    Poly& operator+=(const Poly& r) {
        C.resize(max(sz(C), sz(r.C)));
        rep(i, 0, sz(r.C)) C[i] += r.C[i];
        reduce();
        return *this;
    }

    // Subtract polynomial; time: O(n)
    Poly& operator-=(const Poly& r) {
        C.resize(max(sz(C), sz(r.C)));
        rep(i, 0, sz(r.C)) C[i] -= r.C[i];
        reduce();
        return *this;
    }

    // Multiply by polynomial
    // time: O(n lg n) if using FFT
    Poly operator*(const Poly& r) const {
        int len = sz(C) + sz(r.C) - 1;
        Poly ret;
        ret.C.resize(len);

        if (sz(C)*sz(r.C) < 200) {
            // If you don't need FFT - use just this
            rep(i, 0, sz(C)) rep(j, 0, sz(r.C)) {
                ret.C[i+j] = ret.C[i+j] + C[i]*r.C[j];
            }
        } else {
            int n = 1 << (32 - __builtin_clz(len));
            Vfft a(n), b(n);

            rep(i, 0, sz(C)) a[i] = C[i];
            rep(i, 0, sz(r.C)) b[i] = r.C[i];

            initFFT(n);
            fft<1>(a); fft<1>(b);
            rep(i, 0, sz(a)) a[i] = a[i]*b[i];
            fft<-1>(a);

            rep(i, 0, len) ret.C[i] = a[i].real();
        }

        ret.reduce();
        return ret;
    }

    Poly operator+(const Poly& r) const {
        Poly l = *this; l += r; return l;
    }
    Poly operator-(const Poly& r) const {
        Poly l = *this; l -= r; return l;
    }
    Poly& operator*=(const Poly& r) {
        return *this = *this * r;
    }

    // Derivate polynomial; time: O(n)
    void derivate() {
        rep(i, 1, sz(C)) C[i-1] = C[i]*i;
        C.pop_back();
    }

    // Integrate polynomial; time: O(n)
    void integrate() {
        C.pb(0);
        rep(i, 1, sz(C)) C[i] = C[i-1]/i;
        C[0] = 0;
    }
};


// ---

void run() {
    int n, x; cin >> n >> x;
    Vi prefs;
    prefs.pb(0);

    rep(i, 0, n) {
        int y; cin >> y;
        prefs.pb(prefs.back() + (y < x));
    }

    int size = n*2;
    Poly P(size), Q(size);

    each(i, prefs) {
        P.C[i] += 1;
        Q.C[n-i] += 1;
    }

    Poly res = P*Q;

    Vi seen(n+1);
    ll zero = 0;
    each(y, prefs) {
        zero += seen[y];
        seen[y]++;
    }

    cout << zero << ' ';
    rep(k, 1, n+1) {
        cout << llround(res.C[k+n]) << ' ';
    }
    cout << endl;
}