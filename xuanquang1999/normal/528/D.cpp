#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

const int MAXN = 2e5 + 5;

int n, m, k;
char s[MAXN], t[MAXN];

void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

vector<bool> Solve(char ch) {
    vector<double> data1(n), data2(m);

    vector<int> d(n+1, 0);
    fto(i, 0, n-1) {
        if (s[i] == ch) {
            ++d[max(0, i-k)];
            --d[min(n, i+k+1)];
        }
    }
    fto(i, 1, n) d[i] += d[i-1];

    fto(i, 0, n-1)
        data1[i] = (d[i] > 0);

    int cntCh = 0;
    fto(i, 0, m-1) {
        data2[m-i-1] = (t[i] == ch);
        cntCh += (t[i] == ch);
    }

//    debug(ch);
//    puts("data1:");
//    fto(i, 0, n-1)
//        cout << data1[i] << endl;
//    puts("data2:");
//    fto(i, 0, m-1)
//        cout << data2[i] << endl;

    vector<double> c = conv(data1, data2);

//    puts("res:");
//    fto(i, 0, m+n-2)
//        cout << c[i] << endl;

    vector<bool> res(n);
    fto(i, m-1, m+n-2) {
        int x = round(c[i]);
        res[i-m+1] = (x == cntCh);
    }
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    scanf("%s", t);

    vector<bool> matchA = Solve('A');
    vector<bool> matchC = Solve('C');
    vector<bool> matchG = Solve('G');
    vector<bool> matchT = Solve('T');

    int ans = 0;
    fto(i, 0, n-1)
        if (matchA[i] && matchC[i] && matchG[i] && matchT[i]) ++ans;

    printf("%d\n", ans);

    return 0;
}