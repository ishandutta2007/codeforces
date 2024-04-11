/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct ComplexNumber {
    double real, imag;
    inline ComplexNumber& operator = (const ComplexNumber &c) {real = c.real; imag = c.imag; return *this;}
    friend inline ostream& operator << (ostream &s, const ComplexNumber &c) {return s<<'<'<<c.real<<','<<c.imag<<'>';}
};
inline ComplexNumber operator + (const ComplexNumber &x, const ComplexNumber &y) {
    return {x.real + y.real, x.imag + y.imag};
}
inline ComplexNumber operator - (const ComplexNumber &x, const ComplexNumber &y) {
    return {x.real - y.real, x.imag - y.imag};
}
inline ComplexNumber operator * (const ComplexNumber &x, const ComplexNumber &y) {
    return {x.real * y.real - x.imag * y.imag, x.real * y.imag + x.imag * y.real};
}
inline ComplexNumber operator * (const ComplexNumber &x, double a) {
    return {x.real * a, x.imag * a};
}
inline ComplexNumber operator / (const ComplexNumber &x, double a) {
    return {x.real / a, x.imag / a};
}

const int MAX = 1<<19;  // must be 2^n
ComplexNumber AT[MAX], BT[MAX], CT[MAX];

struct FFT {
    void DTM(ComplexNumber F[], bool inv) {
        int N = MAX;
        for (int t = N; t >= 2; t >>= 1) {
            double ang = acos(-1.0)*2/t;
            for (int i = 0; i < t/2; i++) {
                ComplexNumber w = {cos(ang*i), sin(ang*i)};
                if (inv) w.imag = -w.imag;
                for (int j = i; j < N; j += t) {
                    ComplexNumber f1 = F[j] + F[j+t/2];
                    ComplexNumber f2 = (F[j] - F[j+t/2]) * w;
                    F[j] = f1;
                    F[j+t/2] = f2;
                }
            }
        }
        for (int i = 1, j = 0; i < N; i++) {
            for (int k = N >> 1; k > (j ^= k); k >>= 1);
            if (i < j) swap(F[i], F[j]);
        }
    }
    
    // C is A*B
    void mult(long long A[], long long B[], long long C[]) {
        for (int i = 0; i < MAX; ++i) AT[i] = {(double)A[i], 0.0};
        for (int i = 0; i < MAX; ++i) BT[i] = {(double)B[i], 0.0};
        
        DTM(AT, false);
        DTM(BT, false);
        
        for (int i = 0; i < MAX; ++i) CT[i] = AT[i] * BT[i];
        
        DTM(CT, true);
        
        for (int i = 0; i < MAX; ++i) {
            CT[i] = CT[i] / MAX;
            C[i] = (long long)(CT[i].real + 0.5);
        }
    }
};

int n, m, k; 
string s, t; 

vector<int> cnt;

ll A[MAX], B[MAX], C[MAX];
ll SA[MAX];

void calc(char c) {
    rep(i, MAX) A[i] = B[i] = C[i] = 0;
    int co = 0;
    rep(i, m) if(t[i] == c) ++ co;
    rep(i, n) if(s[i] == c) A[i] = 1LL;
    rep(i, n) SA[i + 1] = SA[i] + A[i];
    rep(i, n) {
        int mi = max(0, i - k), ma = min(n - 1, i + k);
        if(SA[ma + 1] - SA[mi] >= 1) {
            A[i] = 1LL;
        }
    }
    // rep(i, n) cerr << A[i] << " ";
    // cerr << endl;
    rep(i, m) if(t[i] == c) B[i] = 1LL;
    FFT fft; fft.mult(A, B, C);
    rep(i, n - m + 1) {
        if(C[i + m - 1] == co) {
            cnt[i] ++;
        }
        //cerr << C[i + m - 1] << " ";
    }
    //cerr << endl;
}

void solve() {
	cin >> n >> m >> k;
    cin >> s >> t;
    cnt.assign(n, 0);
    reverse(all(t));
    calc('A');
    calc('C');
    calc('G');
    calc('T');
    int ret = 0;
    rep(i, n - m + 1) {
        if(cnt[i] == 4) ++ ret;
    }
    cout << ret << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}