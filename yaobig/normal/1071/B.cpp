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

const int maxn = 2000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5][maxn+5];
int cnt[maxn+5][maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,1,n) rep(j,1,n)
    {
        cnt[i][j] = (i==1 && j==1) ? k : max(cnt[i-1][j],cnt[i][j-1]);
        cnt[i][j] -= s[i][j]!='a';
        if(s[i][j]!='a' && cnt[i][j]>=0) s[i][j] = 'a';
    }
    static int ok[maxn+5][maxn+5];
    ok[1][1] = 1; putchar(s[1][1]);
    rep(sum,3,n*2)
    {
        char c = 'z';
        rep(i,1,n) if(sum-i>=1 && sum-i<=n && (ok[i][sum-i-1] || ok[i-1][sum-i])) chmin(c,s[i][sum-i]);
        putchar(c); 
        rep(i,1,n) if(sum-i>=1 && sum-i<=n && (ok[i][sum-i-1] || ok[i-1][sum-i]) && c==s[i][sum-i]) ok[i][sum-i] = 1;
    }
    puts("");
    return 0;
}