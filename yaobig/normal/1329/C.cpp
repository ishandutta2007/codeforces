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

const int maxn = 1<<20;
const int inf = 0x3f3f3f3f;
const int mod = 1'000'000'007;


int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int h,g; scanf("%d%d",&h,&g);
        int n = (1<<h) - 1, m = (1<<g) - 1;
        vi a(n+1);
        ll ans = 0;
        rep(i,1,n) scanf("%d",&a[i]), ans += a[i];
        vi vec;
        auto getval = [&](int x) {return x<=n ? a[x] : 0;};
        function<void(int)> solve = [&](int u) {
            while(1)
            {
                int now = u;
                static vi sta; sta.clear();
                while(1)
                {
                    sta.pb(now);
                    if(getval(now*2) || getval(now*2+1)) now = getval(now*2)>getval(now*2+1) ? now*2 : now*2+1;
                    else break;
                }
                if(sta.back()<=m) break;
                int N = sz(sta);
                ans -= a[u]; a[u] = 0; vec.pb(u);
                rep(i,1,N-1) swap(a[sta[i-1]], a[sta[i]]);
            }
            if(u*2<=m) solve(u*2);
            if(u*2+1<=m) solve(u*2+1);
        };
        solve(1);
        printf("%lld\n",ans);
        for(auto x: vec) printf("%d ",x);
        puts("");
    }
    return 0;
}