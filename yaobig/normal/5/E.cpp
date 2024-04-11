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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn*2+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) a[i+n] = a[i];
    int mx = 0, st = -1;
    rep(i,1,n) if(chmax(mx,a[i])) st = i;
    rep(i,1,n) a[i] = a[st+i-1];
    stack<pii> sta; sta.push({inf,1});
    ll ans = 0;
    rep(i,1,n)
    {
        int cnt = 0, now = a[i], c = 1;
        while(sta.top().FI<now) cnt += sta.top().SE, sta.pop();
        if(sta.top().FI==now) cnt += sta.top().SE, c += sta.top().SE, sta.pop();
        cnt += sta.top().FI!=inf;
        ans += cnt;
        sta.push({now,c});
    }
    while(sta.top().FI!=a[1])
    {
        int x = sta.top().SE; sta.pop();
        if(sta.top().FI!=a[1] || sta.top().SE>1) ans += x;
    }
    printf("%lld\n",ans);
    return 0;
}