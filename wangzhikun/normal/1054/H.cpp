/*
    Author: Zhikun Wang 
*/
 
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

typedef complex<double> C;
typedef vector<double> vd;
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

const int mod = 490019;

inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}

int id[mod],pw[mod];

int euclid(int a, int b, int &x, int &y) {
    if (b) { int d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

int crt(int a, int m, int b, int n) {
    if (n > m) swap(a, b), swap(m, n);
    int x, y, g = euclid(m, n, x, y);
    assert((a - b) % g == 0); // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m*n/g : x;
}

int id499[499],id491[491],rv499[499],rv491[491],rc[8][8];

int n,m,c,a;

int ans = 0;
int main(){
    cin>>n>>m>>c;
    for(int i=0;i<8;i++){
        rc[i][i] = 1;
        for(int j=0;j<i;j++){
            if((i&j) == j){
                for(int k=0;k<8;k++)rc[i][k]-=rc[j][k];
            }
        }
    }
    int p = 1;
    for(int i=0;i<498;i++){
        assert(!(p == 1 && i!=0));
        id499[p] = i;rv499[i] = p;
        p = p*7%499;
    }
    p = 1;
    for(int i=0;i<490;i++){
        assert(!(p == 1 && i!=0));
        id491[p] = i;rv491[i] = p;
        p = p*7%491;
    }
    vd A[8],B[8];
    for(int i=0;i<8;i++){
        A[i].resize(1000,0);
        B[i].resize(1000);
    }
    A[3].resize(499*491*4,0); B[3].resize(499*491*4,0);
    A[7].resize(499*491*4,0); B[7].resize(499*491*4,0);
    for(int i=0;i<n;i++){
        ll c = 1ll*i*i%(mod-1);
        cin>>a;
        for(int m2 = 0;m2<=(c%2)*4;m2+=4){
            A[m2][0]+=a;
            if(c%491 != 0)
                A[m2+1][id491[c%491]]+=a;
            if(c%499 != 0)
                A[m2+2][id499[c%499]]+=a;
            if(c%491!=0 && c%499!=0)
                A[m2+3][id491[c%491]*998+id499[c%499]]+=a;
        }
    }
    for(int i=0;i<m;i++){
        ll c = 1ll*i*i*i%(mod-1);
        cin>>a;
        for(int m2 = 0;m2<=(c%2)*4;m2+=4){
            B[m2][0]+=a;
            if(c%491 != 0)
                B[m2+1][id491[c%491]]+=a;
            if(c%499 != 0)
                B[m2+2][id499[c%499]]+=a;
            if(c%491!=0 && c%499!=0)
                B[m2+3][id491[c%491]*998+id499[c%499]]+=a;
        }
    }
    auto calc = [](int m2,int m491,int m499,int cc){
        int pv = crt(m491,491,m499,499);
        pv = crt(pv,491*499,m2,2);
        ans = add(ans,mul(cc,mpow(c,pv)));
    };
    for(int i=0;i<8;i++){
        vd C = conv(A[i],B[i]);
        int m2 = i/4,m491 = 0,m499 = 0;
        for(int j=0;j<C.size();j++){
            if((ll)(C[j]+0.5) == 0)continue;
            if(i%4 == 1){m491 = rv491[j%490];}
            if(i%4 == 2){m499 = rv499[j%498];}
            if(i%4 == 3){m491 = rv491[(j/998)%490];m499 = rv499[(j)%998%498];}
            for(int k=0;k<8;k++){
                if(rc[i][k]){
                    calc((k&4)?m2:0,(k&1)?m491:0,(k&2)?m499:0,(((ll)(C[j]+0.5)%mod)*rc[i][k]+mod)%mod);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}