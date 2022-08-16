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
// #define int ll
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
const int MX = 16000005;
const int MAXN = 100005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
 
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
#endif
 
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------------</Consts>-----------------------
/*
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
 
const int FACSZ = 1; // Make sure to change this
 
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
    return mul(mul(ifact[r],ifact[n-r],c),fact[n],c);
} 
*/
// ----------------------</MATH>--------------------------
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
 
void solvethetestcase();
 
signed main(){
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
 

int n,q;
set<int> gg[MAXN];
int a[MAXN];
int prv[MAXN],nxt[MAXN];

unsigned seg[MX];
int lft[MX],rgt[MX],ot[MX];
int sz = 1;

void upd_y(int ind,int l,int r,int x,int y,int val){
    if(l == r){
        seg[ind] += val;
        return;
    }
    int m = (l+r)/2;
    if(y <= m){
        if(!lft[ind]) lft[ind] = ++sz;
        upd_y(lft[ind],l,m,x,y,val);
    }
    else{
        if(!rgt[ind]) rgt[ind] = ++sz;
        upd_y(rgt[ind],m+1,r,x,y,val);
    }
    seg[ind] = seg[lft[ind]]+seg[rgt[ind]];
}

void upd_x(int ind,int l,int r,int x,int y,int val){
    if(l < r){
        int m = (l+r)/2;
        if(x <= m){
            if(!lft[ind]) lft[ind] = ++sz;
            upd_x(lft[ind],l,m,x,y,val);
        }
        else{
            if(!rgt[ind]) rgt[ind] = ++sz;
            upd_x(rgt[ind],m+1,r,x,y,val);
        }
    }
    if(!ot[ind]) ot[ind] = ++sz;
    upd_y(ot[ind],1,r,x,y,val);
}

unsigned query_y(int ind,int l,int r,int x1,int x2,int y1,int y2){
    if(r < y1 or l > y2) return 0;
    if(l >= y1 and r <= y2){
        return seg[ind];
    }
    int m = (l+r)/2;
    return query_y(lft[ind],l,m,x1,x2,y1,y2)+query_y(rgt[ind],m+1,r,x1,x2,y1,y2);
}

unsigned query_x(int ind,int l,int r,int x1,int x2,int y1,int y2){
    if(r < x1 or l > x2) return 0;
    if(l >= x1 and r <= x2){
        if(!ot[ind]) return 0;
        return query_y(ot[ind],1,r,x1,x2,y1,y2);
    }
    int m = (l+r)/2;
    return query_x(lft[ind],l,m,x1,x2,y1,y2)+query_x(rgt[ind],m+1,r,x1,x2,y1,y2);
}

 
void solvethetestcase(){
    cin >> n >> q;
    FOR(i,1,n+1){
        cin >> a[i];
        if(gg[a[i]].empty()) prv[i] = i;
        else prv[i] = (*gg[a[i]].rbegin());
        gg[a[i]].insert(i);
        if(i != prv[i]) upd_x(1,1,n,i,prv[i],i-prv[i]);
    }
    // int segmx = -1,otmx = -1,lftmx = -1,rgtmx = -1;
    // FOR(i,1,sz+1){
    //     if(seg[i]) segmx = i;
    //     if(ot[i]) otmx = i;
    //     if(lft[i]) lftmx = i;
    //     if(rgt[i]) rgtmx = i;
    // }
    // trace(segmx,otmx,lftmx,rgtmx);
    REP(i,q){
        int type; cin >> type;
        if(type == 1){
            int p,x; cin >> p >> x;
            vector<pair<int,pii> > changes;
            auto it = gg[a[p]].upper_bound(p);
            if(it != gg[a[p]].end()){
                if(prv[p] == p){
                    changes.pb({(*it),{prv[(*it)],(*it)}});
                    prv[(*it)] = (*it);
                }
                else{
                    changes.pb({(*it),{prv[(*it)],prv[p]}});  
                    prv[(*it)] = prv[p];
                } 
            }
            it = gg[x].lower_bound(p);
            if(gg[x].empty() or it == gg[x].begin()){
                changes.pb({p,{prv[p],p}});
                prv[p] = p;
            }
            else{
                it --;
                changes.pb({p,{prv[p],(*it)}});
                prv[p] = (*it); 
            }
            gg[a[p]].erase(p);
            a[p] = x;
            gg[a[p]].insert(p);
            it = gg[a[p]].upper_bound(p);
            if(it != gg[a[p]].end()){
                changes.pb({(*it),{prv[(*it)],p}});
                prv[(*it)] = p;
            }
            for(auto y:changes){
                if(y.S.F != y.F) upd_x(1,1,n,y.F,y.S.F,y.S.F-y.F);
                if(y.S.S != y.F) upd_x(1,1,n,y.F,y.S.S,y.F-y.S.S);
            }
        }
        else{
            int l,r; cin >> l >> r;
            cout << query_x(1,1,n,l,r,l,r) << "\n";
        }
        if(sz > 1.5e7){
            REP(j,sz+1){
                seg[j] = 0;
                lft[j] = 0;
                rgt[j] = 0;
                ot[j] = 0;
            }
            sz = 1;
            REP(j,n+1) gg[j].clear();
            FOR(j,1,n+1){
                if(gg[a[j]].empty()) prv[j] = j;
                else prv[j] = (*gg[a[j]].rbegin());
                gg[a[j]].insert(j);
                if(j != prv[j]) upd_x(1,1,n,j,prv[j],j-prv[j]);
            }
        }
        // FOR(j,1,n+1){
        //     trace(j,a[j],prv[j]);
        // }
        // cout << "--------------------------------\n";
    }
    // segmx = -1,otmx = -1,lftmx = -1,rgtmx = -1;
    // FOR(i,1,sz+1){
    //     if(seg[i]) segmx = i;
    //     if(ot[i]) otmx = i;
    //     if(lft[i]) lftmx = i;
    //     if(rgt[i]) rgtmx = i;
    // }
    // trace(segmx,otmx,lftmx,rgtmx);
}