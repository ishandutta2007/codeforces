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

const int maxn = 600;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

bool dp[maxn+5][maxn+5];
int L[maxn+5],R[maxn+5];


int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&L[i],&R[i]);
    rep(len,1,n) rep(l,1,n-len+1)
    {
        int r = l+len-1;
        if(len==1) dp[l][r] = L[l]==1;
        else
        {
            if(len*2-1>=L[l] && len*2-1<=R[l]) dp[l][r] = dp[l+1][r];
            rep(i,1,len-1) dp[l][r] |= dp[l][l+i-1] && dp[l+i][r];
        }
    }
    if(dp[1][n]==0) puts("IMPOSSIBLE");
    else
    {
        static char ans[maxn*2+5];
        function<void(int,int,int)> dfs = [&](int l,int r,int pos)
        {
            if(l==r) ans[pos] = '(', ans[pos+1] = ')';
            else
            {
                int len = r-l+1;
                if(len*2-1>=L[l] && len*2-1<=R[l] && dp[l+1][r]) 
                {
                    ans[pos] = '(';
                    ans[pos+len*2-1] = ')';
                    dfs(l+1,r,pos+1);
                }
                else
                {
                    rep(i,1,len-1) if(dp[l][l+i-1] && dp[l+i][r]) 
                    {
                        dfs(l,l+i-1,pos);
                        dfs(l+i,r,pos+i*2);
                        return;
                    }
                }
            }
        };
        dfs(1,n,1);
        puts(ans+1);
    }
    return 0;
}