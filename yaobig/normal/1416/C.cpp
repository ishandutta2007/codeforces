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

const int maxn = 300'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int main()
{
    int n; scanf("%d",&n);
    static int a[maxn+5];
    rep(i,1,n) scanf("%d",&a[i]);
    vi vec(n);
    rep(i,1,n) vec[i-1] = i;

    static ll low[35], high[35];
    function<void(int,vi &)> solve = [&](int dep,vi &vec) {
        if(sz(vec)==0 || dep<0) return;
        ll rev = 0;
        vi A,B;
        for(auto i: vec)
        {
            if(a[i]>>dep&1) B.pb(i);
            else A.pb(i), rev += sz(B);
        }
        low[dep] += rev;
        high[dep] += 1ll*sz(A)*sz(B) - rev;
        solve(dep-1,A);
        solve(dep-1,B);
    };
    solve(29,vec);
    int ans = 0;
    ll sum = 0;
    rep(i,0,29) sum += min(low[i],high[i]), ans |= (high[i]<low[i])<<i;
    printf("%lld %d\n",sum,ans);
    return 0;
}