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
string to_string(char c) {return "'" + string(1,c) + "'";}
string to_string(bool x) {return x ? "true" : "false";}
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

const int maxn = 400'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        set<pair<pii,pii>> ban;
        auto next = [&](int i) { return i+1<360 ? i+1 : 0;};
        auto prev = [&](int i) { return i==0 ? 360-1 : i-1;};

        rep(i,1,n)
        {
            char op[5]; scanf("%s",op);
            if(op[0]=='C')
            {
                int r,t1,t2; scanf("%d%d%d",&r,&t1,&t2);
                while(t1!=t2)
                {
                    ban.insert(mp(pii{r-1,t1},pii{r,t1}));
                    ban.insert(mp(pii{r,t1},pii{r-1,t1}));
                    t1 = next(t1);
                }
            }
            else
            {
                int r1,r2,t; scanf("%d%d%d",&r1,&r2,&t);
                int t2 = prev(t);
                rep(i,r1,r2-1) ban.insert(mp(pii{i,t},pii{i,t2}));
                rep(i,r1,r2-1) ban.insert(mp(pii{i,t2},pii{i,t}));
            }
        }
        static int dis[21][360]; memset(dis,0x3f,sizeof dis);
        dis[0][0] = 0;
        queue<pii> q; q.push({0,0});
        while(sz(q))
        {
            auto [r,t] = q.front(); q.pop();
            // debug(r,t,dis[r][t]);
            for(auto [nr,nt]: vector<pii>{{r-1,t},{r+1,t},{r,prev(t)},{r,next(t)}}) if(nr>=0 && nr<=20 && ban.count(mp(pii{r,t},pii{nr,nt}))==0)
            {
                if(chmin(dis[nr][nt], dis[r][t]+1)) q.push({nr,nt});
            }
        }
        puts(dis[20][0]!=inf ? "YES" : "NO");
    }
    return 0;
}