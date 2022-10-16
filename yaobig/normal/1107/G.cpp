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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int c[maxn+5],d[maxn+5];
ll sqr(ll x) {return x*x;}

int main()
{
    int n,a; scanf("%d%d",&n,&a);
    rep(i,1,n) scanf("%d%d",&d[i],&c[i]);
    ll ans = 0;
    function<void(int,int)> solve = [&](int l,int r) {
        if(l>r) return;
        int mid = (l+r)>>1;
        solve(l,mid-1); solve(mid+1,r);
        ll base = a-c[mid];
        chmax(ans,base);
        vector<pair<ll,ll>> L,R;
        L.pb({0,0});
        per(i,l,mid-1) L.pb(L.back()), chmax(L.back().FI,sqr(d[i]-d[i+1])), L.back().SE += a-c[i];
        R.pb({0,0});
        rep(i,mid+1,r) R.pb(R.back()), chmax(R.back().FI,sqr(d[i]-d[i-1])), R.back().SE += a-c[i];
        auto work = [&](vector<pair<ll,ll>> &A,vector<pair<ll,ll>> &B) {
            ll mx = 0;
            int ptr = 0;
            for(auto [val,s]: A)
            {
                while(ptr<sz(B) && B[ptr].FI<=val) chmax(mx,B[ptr++].SE);
                chmax(ans,base+s+mx-val);
            }
        };
        work(L,R);
        work(R,L);
    };
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}