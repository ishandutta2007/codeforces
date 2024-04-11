//By TheOneYouWant

#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define ll unsigned long long
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
    c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;

const int LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
const int MAX_N = 3; // Fibonacci matrix, increase/decrease this value as needed

struct Matrix { ll mat[MAX_N][MAX_N]; }; // we will return a 2D array

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans; ll i, j, k;
    for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
    for (ans.mat[i][j] = k = 0; k < MAX_N; k++){
        ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j])%(MOD-1);
        ans.mat[i][j] %= (MOD-1);
    }
    return ans; 
}

// if necessary, use modulo arithmetic

Matrix matPow(Matrix base, ll p) {
    // O(n^3 log p)
    Matrix ans; ll i, j;
    for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++) 
    ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) {
        // iterative version of Divide & Conquer exponentiation
        if (p & 1) ans = matMul(ans, base);    // if p is odd (last bit is on)
        base = matMul(base, base);    // square the base
        p >>= 1;
        // divide p by 2
    }
    return ans; 
}

ll fastpow(ll a, ll p){
    a %= MOD;
    if(p==0) return 1;
    ll z = fastpow(a,p/2);
    z = (z*z)%MOD;
    if(p%2) z = (a*z)%MOD;
    return z%MOD;
}


signed main(){
    fastio;
    
    ll n,f1,f2,f3,c;
    cin>>n>>f1>>f2>>f3>>c;

    Matrix m;
    forn(i,MAX_N){
        forn(j,MAX_N){
            m.mat[i][j] = 0;
        }
    }

    m.mat[0][0] = 1;
    m.mat[0][1] = 1;
    m.mat[0][2] = 1;
    m.mat[1][0] = 1;
    m.mat[2][1] = 1;

    Matrix ans = matPow(m,n-3);

    // ll finalans = 1;
    unsigned long long g1 = (fastpow(c,1)*f1)%MOD;
    unsigned long long g2 = (fastpow(c,2)*f2)%MOD;
    unsigned long long g3 = (fastpow(c,3)*f3)%MOD;

    unsigned long long gn = 1;
    gn *= fastpow(g3,ans.mat[0][0]);
    gn %= MOD;
    gn *= fastpow(g2,ans.mat[0][1]);
    gn %= MOD;
    gn *= fastpow(g1,ans.mat[0][2]);
    gn %= MOD;
    ll fn = 1;
    fn = gn;

    unsigned long long powtoraise = n;
    powtoraise %= (MOD-1);
    powtoraise *= (MOD-2);
    powtoraise %= (MOD-1);

    fn *= fastpow(c,powtoraise);
    fn %= MOD;
    cout<<fn<<ln;
    // cout<<(ll)MOD*MOD<<ln;
    // cout<<(MOD-2)*(MOD-2)<<ln;

    return 0;
}