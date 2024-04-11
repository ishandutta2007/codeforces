#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi pool[maxn+5],ban[maxn+5];
int cnt[maxn+5],a[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) pool[i].clear();
        rep(i,1,n) ban[i].clear();
        rep(i,1,n) cnt[i] = 0;
        vi vec{0};
        rep(i,1,n) scanf("%d",&a[i]), vec.pb(a[i]);
        sort(all(vec)); vec.erase(unique(all(vec)),vec.end());
        auto getid = [&](int x) {return lower_bound(all(vec),x) -vec.begin();};
        int N = sz(vec)-1;
        rep(i,1,n) a[i] = getid(a[i]);
        rep(i,1,n) cnt[a[i]]++;
        vi A;
        rep(i,1,N) if(cnt[i]) A.pb(cnt[i]), pool[cnt[i]].pb(i);
        sort(all(A)); A.erase(unique(all(A)),A.end());
        for(auto sz: A) sort(all(pool[sz]),greater<int>());
        static int mark[maxn+5];
        rep(i,1,n) mark[i] = 0;
        rep(i,1,m)
        {
            int x,y; scanf("%d%d",&x,&y);
            x = getid(x);
            y = getid(y);
            ban[x].pb(y);
            ban[y].pb(x);
        }
        ll ans = 0;
        rep(x,1,N) 
        {
            for(auto y: ban[x]) mark[y] = x;
            mark[x] = x;
            for(auto sz: A) 
            {
                for(auto y: pool[sz]) if(mark[y]!=x)
                {
                    assert(cnt[y]==sz);
                    chmax(ans,1ll*(cnt[x]+cnt[y])*(vec[x]+vec[y]));
                    break;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}