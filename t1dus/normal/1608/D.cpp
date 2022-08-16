// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/ 
// -------------------</optimizations>--------------------
 
// ---------------<Headers and namespaces>----------------
#include <bits/stdc++.h>
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
 
// ---------------</Headers and namespaces>---------------
 
// -----------------<Defines and typedefs>----------------
// typedef tree<int,null_type,less<int>,rb_tree_tag, 
// tree_order_statistics_node_update> indexed_set; // use less_equal for multiset
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
typedef long double LD;
typedef long long ll;
#define int ll
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
 
/*
// -----<SCANF>-----
#define sfi(x) scanf("%d",&x);
#define sfi2(x,y) scanf("%d%d",&x,&y);
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z);
 
#define sfl(x) scanf("%lld",&x);
#define sfl2(x,y) scanf("%lld%lld",&x,&y);
#define sfl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
#define sfl4(x,y,z,x1) scanf("%lld%lld%lld%lld",&x,&y,&z,&x1);
#define sfl5(x,y,z,x1,y1) scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1);
#define sfl6(x,y,z,x1,y1,z1) scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1,&z1);
 
#define sfs(x) scanf("%s",x);
#define sfs2(x,y) scanf("%s%s",x,y);
#define sfs3(x,y,z) scanf("%s%s%s",x,y,z);
// ----</SCANF>-----
 
// ----<PRINTF>-----
#define pfi(x) printf("%d\n",x);
#define pfi2(x,y) printf("%d %d\n",x,y);
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z);
 
#define pfl(x) printf("%lld\n",x);
#define pfl2(x,y) printf("%lld %lld\n",x,y);
#define pfl3(x,y,z) printf("%lld %lld %lld\n",x,y,z);
 
#define pfs(x) printf("%s\n",x);
#define pfs2(x,y) printf("%s %s\n",x,y);
#define pfs3(x,y,z) printf("%s %s %s\n",x,y,z);
 
#define pwe(x) printf("%lld ",x); // print without end
// ----</PRINTF>----
*/
#define FLSH fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x) cout << fixed << setprecision(x); 
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
// ----------------</Defines and typedefs>----------------
 
// -------------------<Debugging stuff>-------------------
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
// ------------------</Debugging stuff>-------------------
 
// ------------------------<Consts>-----------------------
const int MAXN = 300005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
 
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
#endif
 
const int MOD = 998244353;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------------</Consts>-----------------------

// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.
 
// ------------------------</RNG>-------------------------
 
// ----------------------<MATH>---------------------------
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int add(int a, int b, int c = MOD){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c = MOD){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;return(res>=c?res%c:res);}
int muln(int a, int b, int c = MOD){ll res=(ll)a*b;return ((res%c)+c)%c;}
ll mulmod(ll a,ll b, ll m = MOD){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
 
const int FACSZ = MAXN; // Make sure to change this
 
int fact[FACSZ],ifact[FACSZ];
 
void precom(int c = MOD){
    fact[0] = 1;
    FOR(i,1,FACSZ) fact[i] = mul(fact[i-1],i,c);
    ifact[FACSZ-1] = mod_inverse(fact[FACSZ-1],c);
    REPD(i,FACSZ-1){
        ifact[i] = mul(i+1,ifact[i+1],c);
    }
}
 
int ncr(int n,int r,int c = MOD){
    if(r > n) return 0;
    return mul(mul(ifact[r],ifact[n-r],c),fact[n],c);
} 

// ----------------------</MATH>--------------------------
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
 
void solvethetestcase();
 
signed main(){
    precom();
    // comment when using scanf,printf
    FAST_IO
    int t = 1;
    // (UNCOMMENT FOR MULTIPLE TEST CASES)
    // cin >> t;
    FOR(testcase,1,t+1){
        // (UNCOMMENT FOR CODEJAM)
        // printf("Case #%lld: ",testcase); 
        solvethetestcase();
    }
}   
 
int n;
string a[MAXN];
 
void solvethetestcase(){
    cin >> n;
    REP(i,n) cin >> a[i];
    int c1 = 0,c2 = 1,c3 = 1;
    REP(i,n){
        if(!(a[i][0] == '?' or a[i][0] == 'B')) c2 = 0;
        if(!(a[i][1] == '?' or a[i][1] == 'W')) c2 = 0;
    }
    REP(i,n){
        if(!(a[i][0] == '?' or a[i][0] == 'W')) c3 = 0;
        if(!(a[i][1] == '?' or a[i][1] == 'B')) c3 = 0;
    }
    int open = 0,fb = 0,fc = 0,ob = 0,oc = 0,mix = 0;
    REP(i,n){
        if(a[i][0] == '?' and a[i][1] == '?') open++;
        else if(a[i][0] == a[i][1]){
            if(a[i][0] == 'B') fb++;
            else fc++;
        }
        else if(a[i][0] != '?' and a[i][1] != '?') mix++;
        else if(a[i][0] == 'B' or a[i][1] == 'B') ob++;
        else oc++;
    }

    

    // open = x1 full b + x2 full c + (open-x1-x2) others
    // ob = x3 full b + (ob-x3) others
    // oc = x4 full c + (oc-x4) others
    // conditions are x1+x2 <= open ; x3 <= ob ; x4 <= oc ; x1,x2,x3,x4 >= 0 ; fb+x1+x3 = fc+x2+x4 > 0
    // sum over 2^(open-x1-x2) * (open!/(x1!x2!(open-x1-x2)!)) * ncr(ob,x3) * ncr(oc,x4)

    // iterating over i = x1+x2
    // 2^(open-i) * ncr(open,i) * ncr(i,x1) * ncr(ob,x3) * ncr(oc,x4)
    // 2x1 = fc+i+x4-fb-x3

    int ans = (c2+c3);
    // REP(i,open+1){
    //     int cur = mul(power(2LL,open-i),ncr(open,i));
    //     REP(x3,ob+1){
    //         int cur2 = mul(cur,ncr(ob,x3));
    //         REP(x4,oc+1){
    //             int cur3 = mul(cur,ncr(oc,x4));
    //             int x1 = fc+i+x4-fb-x3;
    //             if(x1%2) continue;
    //             x1 /= 2;
    //             if(x1 < 0 or x1 > i) continue;
    //             if(fb+x1+x3 == 0) continue;
    //             ans = add(ans,mul(cur3,ncr(i,x1)));
    //         }
    //     }
    // }

    // open -> (1+x)^2 x^-1
    // fb -> (x)
    // fc -> x^-1
    // ob -> (1+x)
    // oc -> x^-1(1+x)

    int x = 0,opx = 0;

    opx += 2*open;
    x -= open;
    x += fb;
    x -= fc;
    opx += ob;
    opx += oc;
    x -= oc;

    // trace(opx,x);

    // -xth coefficient of (1+x)^opx
    if(x <= 0)
    ans = (ans+ncr(opx,-x))%FMOD;

    // a = b = 0 case removal

    // 2^(open-x1-x2) * (open!/(x1!x2!(open-x1-x2)!)) * ncr(ob,x3) * ncr(oc,x4)
    // x1 = x2 = x3 = x4 = 0
    // 2^open 

    if(fb == 0 and fc == 0){
        ans -= power(2LL,open);
        ans %= FMOD;
        ans += FMOD;
        ans %= FMOD;
    }



    cout << ans << "\n";

}