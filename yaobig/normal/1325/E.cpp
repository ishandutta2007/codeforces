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

const int maxn = 1'000'000;
const int inf = 0x3f3f3f3f;
const int mod = 1073741824;

int main()
{
    static int maxp[maxn+5];
    maxp[1] = 1;
    rep(i,2,maxn) if(maxp[i]==0) for(int j=i;j<=maxn;j+=i) maxp[j] = i;

    int n; scanf("%d",&n);
    map<pii,int> M;
    rep(i,1,n)
    {
        int a; scanf("%d",&a);
        vi vec;
        while(a!=1)
        {
            int p = maxp[a], cnt = 0;
            while(a%p==0) a /= p, cnt++;
            if(cnt&1) vec.pb(p);
        }
        while(sz(vec)<2) vec.pb(1);
        sort(all(vec));
        M[mp(vec[0],vec[1])]++;
    }
    if(M.count({1,1})) return puts("1"), 0;
    static vi e[maxn+5];
    for(auto [it,c]: M)
    {
        if(c>=2) return puts("2"), 0;
        auto [x,y] = it;
        e[x].pb(y); 
        e[y].pb(x);
    }
    int ans = inf;
    rep(rt,1,1000) if(maxp[rt]==rt) 
    {
        static int mark[maxn+5],dis[maxn+5];
        mark[rt] = rt; dis[rt] = 0;
        queue<int> q; q.push(rt);
        while(sz(q))
        {
            int now = q.front(); q.pop();
            for(auto v: e[now]) 
            {
                if(mark[v]!=rt)
                {
                    q.push(v);
                    mark[v] = rt;
                    dis[v] = dis[now] + 1;
                }
                else if(dis[v]>=dis[now]) chmin(ans, dis[now]+dis[v]+1);
            }
        }
    }
    if(ans==inf) puts("-1");
    else printf("%d\n",ans);
    return 0;
}