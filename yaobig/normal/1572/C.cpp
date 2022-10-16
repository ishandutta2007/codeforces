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

const int maxn = 3000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int a[maxn+5];
int nxt[maxn+5],last[maxn+5];
int dp[maxn+5][maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
	{
		int n; scanf("%d",&n);
		rep(i,1,n) last[i]=n+1;
		rep(i,1,n) scanf("%d",&a[i]);
		int ptr=0;
		rep(i,1,n) if(a[i]!=a[i-1]) a[++ptr]=a[i];
		n=ptr;
		per(i,1,n)
		{
			nxt[i]=last[a[i]];
			last[a[i]]=i;
		}
		rep(i,1,n) rep(j,1,n) dp[i][j]=i<j?maxn:0;
		rep(i,1,n) debug(i, nxt[i]);
		rep(len,2,n) rep(l,1,n-len+1)
		{
			int r=l+len-1;
			chmin(dp[l][r],dp[l+1][r]+1);
			for(int now=nxt[l];now<=r;now=nxt[now]) chmin(dp[l][r],dp[l+1][now-1]+1+dp[now][r]);
			debug(l, r, dp[l][r]);
		}
		printf("%d\n",dp[1][n]);
	}
    return 0;
}