//By TheOneYouWant

#pragma GCC optimize ("-O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//By TheOneYouWant
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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


const ll MAX_N = 105; // Fibonacci matrix, increase/decrease this value as needed

struct Matrix { ll mat[MAX_N][MAX_N]; }; // we will return a 2D array

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans; int i, j, k;
    for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
    for (ans.mat[i][j] = k = 0; k < MAX_N; k++){
        ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j])%MOD;
        ans.mat[i][j]%=MOD;
    }
    return ans; 
}

// if necessary, use modulo arithmetic

Matrix matPow(Matrix base, ll p) {
    p%=MOD;
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

int fpow(int a, int p){
    if(p==0) return 1;
    ll z = fpow(a,p/2);
    z = (z*z)%MOD;
    if(p%2) z = (z*a)%MOD;
    return z;
}

signed main(){
    fastio;
    
    int n,k;
    cin>>n>>k;
    v32 v;
    forn(i,n){
        int x;
        cin>>x;
        v.pb(x);
    }
    reverse(v.begin(),v.end());
    ll tot=0;
    forn(i,n){
        if(v[i]) tot++;
    }
    ll cnt=0;
    forn(i,tot){
        if(v[i]) cnt++;
    }
    Matrix m;
    forn(i,tot+1){
        forn(j,tot+1){
            if(i+n-tot<tot){
                m.mat[i][j]=0;
                continue;
            }
            if(abs(i-j)>1) m.mat[i][j]=0;
            else if(i==j){
                m.mat[i][j] = tot*(tot-1)/2 + (n-tot)*(n-tot-1)/2 + i*(tot-i)+(tot-i)*(n-2*tot+i);
            }
            else if(i-j==1){
                m.mat[i][j] = (i)*(n-2*tot+i);
            }
            else if(j-i==1){
                m.mat[i][j] = (tot-i)*(tot-i);
            }
            m.mat[i][j]%=MOD;
        }
    }
    // forn(i,tot+1){
    //     forn(j,tot+1){
    //         cout<<m.mat[i][j]<<" ";
    //     }
    //     cout<<ln;
    // }
    Matrix ans = matPow(m,k);
    ll a1=0,a2=0;
    a1 = ans.mat[cnt][tot];
    forn(i,tot+1) {
        a2+=ans.mat[cnt][i];
        a2%=MOD;
    }
    ll ansf = 0;
    ansf = a1;
    ansf *= fpow(a2,MOD-2);
    cout<<(ansf)%MOD<<ln;
    return 0;
}