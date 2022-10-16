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

const int maxn = 100000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x) {for(;i<=n;i+=i&-i) a[i]+=x;}
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans+=a[i];
        return ans;
    }
};
BIT<int> bit;

vi pool[maxn+5];
char s[maxn+5],t[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        rep(i,0,25) pool[i].clear();
        per(i,1,n) pool[(int)(s[i]-'a')].pb(i);
        bit.init(n);
        ll ans = 1ll<<60, step = 0;
        rep(i,1,n)
        {
            int mn = inf, c = t[i]-'a';
            rep(j,0,c-1) if(sz(pool[j])) chmin(mn,pool[j].back()-bit.ask(pool[j].back())-1);
            if(mn!=inf) chmin(ans,step+mn);
            if(sz(pool[c])==0) break;
            int pos = pool[c].back();
            step += pos - bit.ask(pos) - 1;
            pool[c].pop_back();
            bit.add(pos,1);
        }
        if(ans==1ll<<60) puts("-1");
        else printf("%lld\n",ans);
    }
    return 0;
}