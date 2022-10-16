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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 1'000'000'007;

vi e[maxn+5];
int a[maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y); e[y].pb(x);
    }
    vi vec;
    function<void(int,int)> orient = [&](int now,int fa) {
        vec.pb(now);
        for(auto v: e[now]) if(v!=fa) orient(v,now);
    };
    orient(min_element(a+1,a+n+1) - a, 0);

    auto check = [&](int x) {
        static vi vis; vis.assign(n+1,0);
        int ans = 0;
        function<pii(int,int)> dfs = [&](int now,int fa) {
            vis[now] = 1;
            int sum = 1, mx = -1, smx = -1;
            for(auto v: e[now]) if(v!=fa)
            {
                auto [val,full] = a[v]>=x ? dfs(v,now) : pii{0,0};
                if(full) sum += val;
                else if(val>mx) smx = mx, mx = val;
                else chmax(smx,val);
            }
            chmax(ans, sum + max(mx,0) + max(smx,0));
            return mx==-1 ? pii{sum,1} : pii{sum+mx,0};
        };

        for(auto i: vec) if(a[i]>=x && vis[i]==0) dfs(i,0);
        return ans>=k;
    };

    int l = 1, r = 1'000'000+1;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(check(mid)) l = mid+1;
        else r = mid;
    }
    printf("%d\n",r-1);
    return 0;
}