#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = isz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        For(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    For(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    For(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) For(j,0,k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(isz(a) + isz(b) - 1);
    int L = 32 - __builtin_clz(isz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(bend(a), begin(in));
    For(i,0,isz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    For(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    For(i,0,isz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

const int N = 5e5 + 5;

vi divi[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
For(i, 1, N){
    for (int j = i; j < N; j += i){
        divi[j].push_back(i);
    }
}
int q; cin >> q; while (q--){
    int n; string s;
    cin >> n >> s;

    vd a, b;
    For(i, 0, n){
        if (s[i] == 'V'){
            a.push_back(1);
        }
        else{
            a.push_back(0);
        }
    }
    FordE(i, n - 1, 0){
        if (s[i] == 'K'){
            b.push_back(1);
        }
        else{
            b.push_back(0);
        }
    }
    vd c = conv(a, b);
    vi ck(n + 1, 1);
    For(i, 1, n){
        if (c[n - 1 - i] > 1e-6 || c[n - 1 + i] > 1e-6){
            Fora(&v, divi[i]){
                ck[v] = 0;
            }
        }
    }
    vi ans;
    ForE(i, 1, n){
        if (ck[i]){
            ans.push_back(i);
        }
    }
    cout << isz(ans) << endl;
    Fora(&v, ans){
        cout << v << ' ';
    } cout << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/