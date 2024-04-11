#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template <typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x : v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[maxn+5];
int a[maxn+5],b[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) e[i].clear();
        rep(i,2,n) scanf("%d",&a[i]);
        rep(i,2,n) scanf("%d",&b[i]);
        rep(i,1,m)
        {
            int x,y; scanf("%d%d",&x,&y);
            e[x].pb(y);
            e[y].pb(x);
        }

        auto check = [&](ll st) {
            vi q{1};
            vector<bool> in(n+1),vis(n+1);
            in[1] = 1;
            stack<int> sta;
            function<bool(int,int,ll)> dfs = [&](int now,int fa,ll val) {
                if(in[now] || vis[now])
                {
                    while(sz(sta)) q.pb(sta.top()), in[sta.top()] = 1, sta.pop();
                    st = val;
                    return 1;
                }
                if(val <= a[now]) return 0;
                vis[now] = 1;
                sta.push(now);
                val += b[now]; 
                for(auto v: e[now]) if(v!=fa && dfs(v,now,val)) return 1;
                vis[now] = 0;
                sta.pop();
                return 0;
            };
            while(sz(q)!=n)
            {
                int ok = 0;
                rep(i,1,n) vis[i] = 0;
                rep(i,0,sz(q)-1) 
                {
                    int s = q[i];
                    for(auto v: e[s]) if(in[v]==0 && dfs(v,s,st)) {ok = 1; break;} 
                    if(ok) break;
                }
                if(ok == 0) break;
            }
            return sz(q)==n;
        };

        int l=1,r=1000000001;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}