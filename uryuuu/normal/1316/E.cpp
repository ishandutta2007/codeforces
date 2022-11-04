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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

struct node
{
    int a,s[10];
}a[maxn];

bool cmp(node a,node b)
{
    return a.a>b.a;
}

int n,p,k,b[1<<10];
ll dp[1<<10],tp[1<<10];

int main()
{
    sync;
    cin>>n>>p>>k;
    rep(i,1,n)
    {
        cin>>a[i].a;
    }
    rep(i,1,n)
    {
        rep(j,0,p-1)
        {
            cin>>a[i].s[j];
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<(1<<p);i++)
    {
        for(int j=0;j<p;j++)
        {
            if(i&(1<<j))
                b[i]++;
        }
    }
    for(int i=0;i<(1<<p);i++)
        dp[i]=-1e18;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        memcpy(tp,dp,sizeof(tp));
        for(int s=0;s<(1<<p);s++)
        {
            if(i-b[s]<=k)
            {
                dp[s]=tp[s]+a[i].a;
            }
            for(int j=0;j<p;j++)
            {
                if(s&(1<<j))
                    dp[s]=max(dp[s],tp[s^(1<<j)]+a[i].s[j]);
            }
        }
    }
    cout<<dp[(1<<p)-1]<<endl;
    return 0;
}