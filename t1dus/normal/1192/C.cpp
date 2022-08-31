// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------

#pragma GCC optimize("unroll-loops")

/*
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
// typedef tree<int,null_type,less<int>,rb_tree_tag, \
tree_order_statistics_node_update> indexed_set; // use less_equal for multiset
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
#define TRACE
 
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
const int MAXN = 1000005;
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

/*

// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.
 
// ------------------------</RNG>-------------------------
 
// ----------------------<MATH>---------------------------


*/

int add(int a, int b, int c = MOD){int res=a+b;return(res>=c?res-c:res);}
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;return(res>=c?res%c:res);}


// ----------------------</MATH>--------------------------
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
 
void solvethetestcase();
 
signed main(){
    // comment when using scanf,printf
    FAST_IO

    int t = 1;
    // (UNCOMMENT FOR MULTIPLE TEST CASES) \
    cin >> t;
    FOR(testcase,1,t+1){
        // (UNCOMMENT FOR CODEJAM) \
        printf("Case #%lld: ",testcase); 
        solvethetestcase();
    }
}   
 
int n;
int cnt[11][65][65];
int dp[11][65][65][65];

int MXa = 26,MXA = 26,MXI = 10;

int ctoi(char c){
    if(c-'a' >= 0) return c-'a';
    if(c-'A' >= 0) return (c-'A')+MXa;
    return (c-'0')+MXa+MXA;
}
 
void solvethetestcase(){
    cin >> n;
    set<string> gg;
    REP(i,n){
        string s; cin >> s;
        gg.insert(s);
        reverse(all(s));
        gg.insert(s);    
    }
    for(auto s:gg){
        cnt[s.length()][ctoi(s[0])][ctoi(s[s.length()-1])] ++;
    }
    FOR(i,3,11){
        REP(j,MXa+MXA+MXI){
            FOR(k,j,MXa+MXA+MXI){
                FOR(l,k,MXa+MXA+MXI){
                    REP(m,MXa+MXA+MXI){
                        dp[i][j][k][l] = add(dp[i][j][k][l],mul(mul(cnt[i][j][m],cnt[i][k][m]),cnt[i][l][m]));
                        dp[i][j][l][k] = dp[i][k][j][l] = dp[i][k][l][j] = dp[i][l][j][k] = dp[i][l][k][j] = dp[i][j][k][l];
                    }
                }
            }
        }
    }
    int ans = 0;
    FOR(i,3,11){
        REP(j,MXa+MXA+MXI){
            REP(k,MXa+MXA+MXI){
                REP(l,MXa+MXA+MXI){
                    REP(m,MXa+MXA+MXI){
                        int cur = mul(mul(dp[i][j][k][l],dp[i][m][k][l]),mul(dp[i][j][m][l],dp[i][j][k][m]));
                        ans = add(ans,cur);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}