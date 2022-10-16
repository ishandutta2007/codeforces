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

const int maxn = 500'000;
const int inf = 0x3f3f3f3f;
const int mod = 1073741824;

int main()
{
    int n; scanf("%d",&n);
    vector<pii> a(n);
    for(auto &[x,y]: a)
    {
        static char s[maxn+5]; scanf("%s",s);
        int l = strlen(s);
        rep(i,0,l-1) if(s[i]=='B') x++; else y++;
    }
    auto solve = [&](int d){
        int xmn = 0, ymn = 0, dmn = -inf;
        int xmx = maxn, ymx = maxn, dmx = inf;
        for(auto [x,y]: a)
        {
            chmax(xmn, x-d); chmax(ymn, y-d); chmax(dmn, x-y-d);
            chmin(xmx, x+d); chmin(ymx, y+d); chmin(dmx, x-y+d);
        }
        if(xmn>xmx || ymn>ymx || dmn>dmx || xmn-ymx>dmx || xmx-ymn<dmn) return pii{-1,-1};
        int x = -1, y = -1;
        if(xmx-ymx>dmx) y = ymx, x = dmx+y;
        else if(xmx-ymx<dmn) x = xmx, y = x-dmn;
        else x = xmx, y = ymx;
        return pii{x,y};
    };
    int l = 0, r = maxn;
    while(l<r)
    {
        int mid = (l+r)>>1;
        auto [x,y] = solve(mid);
        if(x==-1) l = mid+1;
        else r = mid;
    }
    auto [x,y] = solve(r);
    printf("%d\n",r);
    rep(i,1,x) putchar('B');
    rep(i,1,y) putchar('N');
    puts("");
    return 0;
}