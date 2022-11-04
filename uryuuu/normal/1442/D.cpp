#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;
ll a[3005][3005];
ll d[3005];
ll ans;
ll n,k;
ll pre[3005];

void solve(int l,int r,ll dp[])
{
    ll sum=0;
    ans=max(ans,dp[k]);
    if(l==r)
    {
        for(int i=1;i<=a[l][0];i++)
        {
            sum+=a[l][i];
            ans=max(dp[k-i]+sum,ans);
        }
        return;
    }
    int mid=(l+r)/2;
    ll dpl[3005];
    ll dpr[3005];
    for(int i=0;i<=k;i++)
    {
        dpl[i]=dpr[i]=dp[i];
    }
    for(int i=l;i<=mid;i++)
    {
        for(int j=k;j>=a[i][0];j--)
        {
            dpr[j]=max(dpr[j-a[i][0]]+pre[i],dpr[j]);
        }
    }
    for(int i=mid+1;i<=r;i++)
    {
        for(int j=k;j>=a[i][0];j--)
        {
            dpl[j]=max(dpl[j-a[i][0]]+pre[i],dpl[j]);
        }
    }
    solve(l,mid,dpl);
    solve(mid+1,r,dpr);
}

int main()
{
    sync;
    cin>>n>>k;
    ll x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
        {
            cin>>x;
            if(j<=k)
            {
                a[i][j]=x;
                pre[i]+=a[i][j];
            }
        }
        a[i][0]=min(a[i][0],k);
    }
    ans=0;
    solve(1,n,d);
    cout<<ans<<endl;

    return 0;
}