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

const int maxn = 100'000;
const int inf = 0x3f3f3f3f;
const int mod = 1073741824;

int main()
{
    int n; scanf("%d",&n);
    static ll a[maxn+5];
    rep(i,1,n) scanf("%lld",&a[i]);

    auto solve = [&](int l,int r) {
        if(l>r) puts("1 1\n0");
        else
        {
            printf("%d %d\n",l,r);
            int L = r-l+1;
            rep(i,l,r)
            {
                if(a[i]%n==0) printf("%d%c",0," \n"[i==r]);
                else printf("%lld%c",a[i]*L," \n"[i==r]), a[i] *= L+1;
            }
        }
    };
    solve(1,n-1);
    solve(2,n);
    printf("%d %d\n",1,n);
    rep(i,1,n) printf("%lld%c",-a[i]," \n"[i==n]);
    rep(i,1,n) assert(a[i]%n==0);
    return 0;
}