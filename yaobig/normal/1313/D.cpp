#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[1<<8],id[maxn+5];

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    vector<pii> vec;
    rep(i,1,n)
    {
        int l,r; scanf("%d%d",&l,&r);
        vec.pb({l,i});
        vec.pb({r+1,-i});
    }
    sort(vec.begin(),vec.end());
    set<int> unused;
    rep(i,0,k-1) unused.insert(i);
    int N=1<<k,pre=1;
    rep(i,1,N-1) dp[i]=-inf;
    for(auto [now,x]: vec)
    {
        rep(msk,0,N-1) if(__builtin_popcount(msk)&1) dp[msk]+=now-pre;
        pre=now;
        if(x>0)
        {
            id[x]=*unused.begin(); unused.erase(id[x]);
            rep(msk,0,N-1) if(msk&(1<<id[x])) dp[msk]=dp[msk^(1<<id[x])];
        }
        else
        {
            unused.insert(id[-x]);
            rep(msk,0,N-1) if(msk&(1<<id[-x])) chmax(dp[msk^(1<<id[-x])],dp[msk]),dp[msk]=-inf;
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}