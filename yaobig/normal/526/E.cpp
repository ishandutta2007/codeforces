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

int a[maxn*2+5],jump[maxn*2+5];

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]), a[i+n] = a[i];
    while(q--)
    {
        ll b; scanf("%lld",&b);
        ll sum = 0;
        int ptr = 1;
        rep(i,1,n)
        {
            while(ptr<=n*2 && sum+a[ptr]<=b) sum += a[ptr++];
            jump[i] = jump[i+n] = ptr-i;
            sum -= a[i];
        }
        int st = min_element(jump+1,jump+n+1) - jump;
        int ans = inf;
        rep(i,st+1,st+jump[st])
        {
            int s = i>n ? i-n : i;
            int now = s, cnt = 0;
            while(now<s+n) now += jump[now], cnt++;
            chmin(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}