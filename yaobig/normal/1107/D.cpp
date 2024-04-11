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

const int maxn = 5200;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

bool a[maxn+5][maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        static char s[maxn+5]; scanf("%s",s+1);
        rep(j,1,n/4) 
        {
            int x = s[j]>='0' && s[j]<='9' ? s[j]-'0' : s[j]-'A'+10;
            rep(k,0,3) a[i][j*4-k] = x>>k&1;
        }
    }
    int ans = n;
    rep(i,1,n) rep(j,1,n-1) if(a[i][j]!=a[i][j+1]) ans = __gcd(ans,j);
    rep(i,1,n-1) rep(j,1,n) if(a[i][j]!=a[i+1][j]) ans = __gcd(ans,i);
    printf("%d\n",ans);
    return 0;
}