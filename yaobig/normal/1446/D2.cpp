#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
template<class T> int sz(T A) { return A.size(); }
template<class T> inline bool chmax(T &a, T b) { if(a<b) {a=b; return 1;} return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b<a) {a=b; return 1;} return 0; }
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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int main()
{
    int n; scanf("%d",&n);
    static int a[maxn+5];
    rep(i,1,n) scanf("%d",&a[i]);
    
    static vi pool[maxn+5];
    rep(i,1,n) pool[a[i]].pb(i);
    int Msz = 0, best = -1;
    rep(i,1,n) if(chmax(Msz, sz(pool[i]))) best = i;
    set<int> S(all(pool[best]));
    S.insert(0); S.insert(n+1);
    int ans = 0;
    rep(val,1,n) if(val != best && sz(pool[val])) 
    {
        vi vec;
        for(auto x: pool[val]) 
        {
            auto it = S.lower_bound(x);
            if(*prev(it) != 0) vec.pb(*prev(it)), S.erase(prev(it));
            if(*it != n + 1) vec.pb(*it), S.erase(it);
        }
        for(auto x: vec) S.insert(x);
        vec.insert(vec.end(), all(pool[val]));
        sort(all(vec));
        for(auto x: pool[val]) S.insert(x);
        map<int, int> mn;
        for(auto x: vec)
        {
            auto it = S.find(x);
            auto get = [&](int pos)
            {
                auto &P = pool[best];
                auto &Q = pool[val];
                int a = upper_bound(all(P), pos) - P.begin();
                int b = upper_bound(all(Q), pos) - Q.begin();
                return a - b;
            };
            int c = get(*prev(it));
            if(mn.count(c) == 0) mn[c] = inf;
            chmin(mn[c], *prev(it));
            int d = get(*next(it) - 1);
            if(mn.count(d) == 0) mn[d] = inf;
            chmax(ans, *next(it) - 1 - mn[d]);
        }
        for(auto x: pool[val]) S.erase(x);
    }
    printf("%d\n",ans);
    return 0;
}