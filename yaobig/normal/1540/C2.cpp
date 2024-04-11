#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

int c[maxn+5];
int b[maxn+5],d[maxn+5];
int dp[maxn*maxn+5];

int mydiv(int x,int y)
{
    int res=x/y;
    while(res*y>x) res--;
    return res;
}

int ans[maxn*2+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&c[i]);
    rep(i,1,n-1) scanf("%d",&b[i]);

    d[1]=0;
    rep(i,2,n) d[i]=d[i-1]+b[i-1]; 
    rep(i,2,n) d[i]+=d[i-1]; 

    int mn=c[1],sum=c[1];
    rep(i,2,n) 
    {
        sum+=c[i];
        chmin(mn,mydiv(sum-d[i],i));
    }

    auto solve=[&](int x){
        d[1]=x;
        rep(i,2,n) d[i]=d[i-1]+b[i-1];
        rep(i,2,n) d[i]+=d[i-1];
        int M=maxn*maxn;
        rep(i,0,M) dp[i]=1;
        rep(i,1,n)
        {
            per(j,0,M) if(j-c[i]-1>=0) dp[j]=(dp[j]+mod-dp[j-c[i]-1])%mod;
            rep(j,0,M) if(j<d[i]) dp[j]=0;
            rep(j,1,M) dp[j]=(dp[j]+dp[j-1])%mod;
        }
        return dp[M];
    };
    rep(i,0,100) ans[i]=solve(mn-i);

    int q; scanf("%d",&q);
    while(q--)
    {
        int x; scanf("%d",&x);
        if(x>mn) puts("0");
        else printf("%d\n",ans[min(100,mn-x)]);
    }
	return 0;
}