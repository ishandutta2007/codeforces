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

const int maxn = 505;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct trie
{
    #define C 10
    #define MAXN maxn
    int next[MAXN+5][C];
    array<int,MAXN+5> cnt;
    int tot,root;
    int newnode()
    {
        cnt[++tot]=0;
        memset(next[tot],0,sizeof next[tot]);
        return tot;
    }
    void init()
    {
        tot=0;
        root=newnode();
    }
    void ins(char *s,int x)
    {
        int l=strlen(s),now=root;
        rep(i,0,l-1)
        {
            int id=s[i]-'0';
            if(!next[now][id]) next[now][id]=newnode();
            now=next[now][id];
        }
        cnt[now]+=x;
    }

    int dp[maxn+5][maxn+5][12]; 
    // dp[now][i][j] = the minimum sum in the subtree rooted at now if:
    // 1. the closest bar is i level above;
    // 2. j bars have been used in the subtree rooted at now. 
    void dfs(int now,int dep,int k)
    {
        rep(i,0,dep) rep(j,0,k) dp[now][i][j] = i==0 && j==0 ? inf : cnt[now] * i;
        for(auto v: next[now]) if(v)
        {
            dfs(v,dep+1,k);
            rep(i,0,dep) per(j,0,k)
            {
                int tmp = inf;
                rep(j2,0,j) chmin(tmp, dp[now][i][j-j2] + min(dp[v][i+1][j2],dp[v][0][j2]));
                dp[now][i][j] = tmp;
            }
        }
    }
    #undef C
    #undef MAXN
}tr;


int main()
{
    int n,k; scanf("%d%d",&n,&k);
    tr.init();
    rep(i,1,n)
    {
        static char s[maxn+5]; int x; scanf("%s%d",s,&x);
        tr.ins(s,x);
    }
    tr.dfs(1,0,k+1);
    printf("%d\n",tr.dp[1][0][k+1]);
    return 0;
}