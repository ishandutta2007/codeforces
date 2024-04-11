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
template <typename A> string to_string(A v) 
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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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

const int maxn = 200000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}

int cnt[40],pw[maxn+5];

int main()
{
    pw[0] = 1;
    rep(i,1,maxn) pw[i] = 2ll*pw[i-1]%mod;
    int cas = 1; //scanf("%d",&cas); 
    while(cas--) 
    {
        int n; scanf("%d",&n);
        rep(i,1,n)
        {
            int x; scanf("%d",&x);
            int c = 0;
            while(x%2==0) x/=2, c++;
            cnt[c]++;
        }
        int ans = 0;
        rep(i,1,30) if(cnt[i])
        {
            int s = 0;
            rep(j,i,30) s+=cnt[j];
            chadd(ans,pw[s-1]);
        }
        //rep(i,0,30) debug(i,cnt[i]);
        //debug(ans);
        printf("%d\n",(pw[n]-1-ans+mod)%mod);
    }
    return 0;
}