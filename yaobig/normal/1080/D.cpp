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

const int maxn = 1010;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

ll dp[35];

int main()
{
    rep(i,1,31) dp[i] = dp[i-1]*4+1;
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; ll k; scanf("%d%lld",&n,&k);
        if(n>=32) printf("YES %d\n",n-1);
        else
        {
            if(k>dp[n]) puts("NO");
            else 
            {
                ll A = 0, B = 0, fac = 1;
                int ans = -1;
                rep(i,1,n) 
                {
                    A += (1<<i)-1;
                    B += fac*dp[n-i];
                    fac = fac*2+3;
                    if(A>k) break;
                    else if(A+B>=k) {ans = i; break;}
                }
                if(ans==-1) puts("NO");
                else printf("YES %d\n",n-ans);
            }
        }
    }
    return 0;
}