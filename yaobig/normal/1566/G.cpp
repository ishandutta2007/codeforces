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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

set<pii> e[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    map<pii,int> M;
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x].insert({w,y});
        e[y].insert({w,x});
        if(x>y) swap(x,y);
        M[{x,y}] = w;
    }
    
    set<pair<int,pii>> S;
    auto add = [&] (int now) {
        int c = 0;
        for(auto [w,v]: e[now]) 
        {
            if(++c>3) break;
            int j = 0;
            for(auto [w2,u]: e[v]) 
            {
                if(++j>3) break;
                if(u==now) {S.insert(mp(w,pii{now,v})); break;}
            }
        }
    };
    
    auto del = [&] (int now) {
        int c = 0;
        for(auto [w,v]: e[now])
        {
            if(++c>3) break;
            S.erase(mp(w,pii{now,v}));
        }
    };
    auto askthree = [&] (int now) {
        if(sz(e[now])<3) return 1ll<<60;
        ll ans = 0;
        int c = 0;
        for(auto [w,v]: e[now])
        {
            if(++c>3) break;
            ans += w;
        }
        return ans;
    };
    auto asksecond = [&] (int x,int y) {
        ll ans = 1ll<<60;
        int c1 = 0;
        for(auto [w,u]: e[x])
        {
            if(++c1>3) break;
            int c2 = 0;
            for(auto [z,v]: e[y])
            {
                if(++c2>3) break;
                if(x==u || x==v || y==u || y==v || u==v) continue;
                chmin(ans,1ll*w+z);
            }
        }
        return ans;
    };
    auto query = [&] () {
        assert(sz(S));
        auto [w,it] = *S.begin();
        auto [x,y] = it;
        ll ans = 1ll<<60;
        chmin(ans, askthree(x));
        chmin(ans, askthree(y));
        chmin(ans, asksecond(x,y));
        //debug(w,x,y);
        //debug(askthree(x), askthree(y));
        //debug(asksecond(x,y));
        ll tmp = 1ll<<60;
        for(auto [w,it]: S)
        {
            auto [u,v] = it;
            if(u==x || u==y || v==x || v==y) continue;
            tmp = w;
            break;
        }
        chmin(ans,tmp+w);
        return ans;
    }; 
    rep(i,1,n) add(i);
    printf("%lld\n",query());
    int q; scanf("%d",&q);
    while(q--)
    {
        int op,x,y,w=0; scanf("%d%d%d",&op,&x,&y);
        if(op) scanf("%d",&w);
        if(x>y) swap(x,y);
        del(x); del(y);
        if(op==1)
        {
            M[{x,y}] = w;
            e[x].insert({w,y});
            e[y].insert({w,x});
        }
        else
        {
            w = M[{x,y}];
            M.erase({x,y});
            e[x].erase({w,y});
            e[y].erase({w,x});
        }
        add(x); add(y);
        printf("%lld\n",query());
    }
    return 0;
}