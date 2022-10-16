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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5];

const int MAXA = 1<<20;
int q[MAXA][2];

int solve(int n,int d)
{
    rep(i,0,MAXA-1) rep(j,0,1) q[i][j]=-1;
    q[0][0]=0;
    int last=0,ps=0,ans=0;
    rep(i,1,n)
    {
        ps ^= a[i] >> (d+1);
        if((a[i]>>d&1)==0) last=i;
        if(q[ps][i&1]>=last) chmax(ans,i-q[ps][i&1]);
        if(q[ps][i&1]<last) q[ps][i&1]=i;
    }
    return ans;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int ans=0;
    rep(d,0,19) chmax(ans,solve(n,d));
    printf("%d\n",ans);
    return 0;
}