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


int main()
{
    int n,k,m; scanf("%d%d%d",&n,&k,&m);
    vector<pii> A;
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        if(A.empty() || A.back().FI!=x) A.pb({x,0});
        A.back().SE++;
        if(A.back().SE==k) A.pop_back();
    }
    deque<pii> q;
    for(auto x: A) q.pb(x);
    int cnt = 0;
    while(sz(q)>1)
    {
        if(q.front().FI!=q.back().FI || q.front().SE+q.back().SE<k) break;
        int x = q.front().SE; q.pop_front();
        cnt++;
        q.back().SE -= k-x;
        if(q.back().SE==0) q.pop_back();
    }
    ll ans = 0;
    if(sz(q)==1)
    {
        ll tot = 1ll*q.back().SE*m%k;
        if(tot) ans = tot + 1ll*k*cnt;
    } 
    else if(sz(q)>1)
    {
        ll tot = 0;
        while(sz(q)) tot += q.back().SE, q.pop_back();
        ans = 1ll*tot*m + 1ll*k*cnt;
    }
    printf("%lld\n",ans);
    return 0;
}