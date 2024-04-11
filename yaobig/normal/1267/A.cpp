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
const int mod = 998244353;

struct node 
{
    ll a,b,t;
    bool operator < (const node &rhs) const {return a+t>rhs.a+rhs.t;}
};


int main()
{
    int n; scanf("%d",&n);
    priority_queue<node> pq;
    rep(i,1,n)
    {
        ll a,b,t; scanf("%lld%lld%lld",&a,&b,&t);
        pq.push(node{a,b,t});
    }
    ll now = 0, ans = 0;
    using pll = pair<ll,ll>;
    priority_queue<pll, vector<pll>, greater<pll> > pq2;
    while(1)
    {
        while(sz(pq) && pq.top().a<=now) 
        {
            auto [a,b,t] = pq.top(); pq.pop();
            pq2.push({t,b});
        }
        while(sz(pq2) && now+pq2.top().FI>pq2.top().SE) pq2.pop();
        ll t1 = sz(pq) ? pq.top().a+pq.top().t : 1ll<<62;
        ll t2 = sz(pq2) ? now+pq2.top().FI : 1ll<<62;
        ll best = min(t1,t2);
        if(best==1ll<<62) break;;
        if(t1==best) 
        {
            now = best;
            ans++;
        }
        else 
        {
            auto [t,b] = pq2.top();
            ll r = min(t1,b);
            ll cnt = (r-now)/t;
            now += cnt*t;
            ans += cnt;
        }
    }
    printf("%lld\n",ans);
    return 0;
}