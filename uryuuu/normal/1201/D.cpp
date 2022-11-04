#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

struct node
{
    ll l,r,cnt;
}a[maxn];
ll b[maxn],pre[maxn],nxt[maxn];

ll dp[maxn][5];

int main()
{
    sync;
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    ll x,y;
    for(int i=0;i<=n;i++)
    {
        a[i].l=99999999999;
        dp[i][0]=dp[i][1]=999999999999999;
    }
    ll R=1;
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        a[x].cnt++;
        a[x].l=min(y,a[x].l);
        a[x].r=max(y,a[x].r);
        R=max(R,x);
    }
    for(int i=1;i<=q;i++)
    {
        int id;
        cin>>id;
        b[id]=1;
    }
    
    pre[0]=0;
    nxt[m+1]=0;
    for(int i=1;i<=m;i++)
    {
        pre[i]=pre[i-1];
        if(b[i])
            pre[i]=i;
    }
    for(int i=m;i>=1;i--)
    {
        nxt[i]=nxt[i+1];
        if(b[i])
            nxt[i]=i;
    }
    b[0]=0;
    b[q+1]=99999999;
    ll sum=R-1;
    dp[1][0]=dp[1][1]=0;
    ll LL=1,RR=1;
    if(a[1].cnt)
    {
        dp[1][0]=a[1].r-1+a[1].r-a[1].l;
        dp[1][1]=a[1].r-1;
        LL=a[1].l;
        RR=a[1].r;
    }
//    cout<<dp[1][0]<<' '<<dp[1][1]<<endl;
    ll L0,R0,L1,R1;
    for(int i=2;i<=R;i++)
    {
        if(a[i].cnt==0)
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            continue;
        }
        L0=pre[LL];
        R0=nxt[LL];
        L1=pre[RR];
        R1=nxt[RR];
//        cout<<LL<<' '<<RR<<' '<<L0<<' '<<R0<<' '<<L1<<' '<<R1<<endl;
        if(L0)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+abs(L0-LL)+abs(L0-a[i].l)+a[i].r-a[i].l);
            dp[i][0]=min(dp[i][0],dp[i-1][0]+abs(L0-LL)+abs(L0-a[i].r)+a[i].r-a[i].l);
        }
        if(R0)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+abs(R0-LL)+abs(R0-a[i].l)+a[i].r-a[i].l);
            dp[i][0]=min(dp[i][0],dp[i-1][0]+abs(R0-LL)+abs(R0-a[i].r)+a[i].r-a[i].l);
        }
        if(L1)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+abs(L1-RR)+abs(L1-a[i].l)+a[i].r-a[i].l);
            dp[i][0]=min(dp[i][0],dp[i-1][1]+abs(L1-RR)+abs(L1-a[i].r)+a[i].r-a[i].l);
        }
        if(R1)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+abs(R1-RR)+abs(R1-a[i].l)+a[i].r-a[i].l);
            dp[i][0]=min(dp[i][0],dp[i-1][1]+abs(R1-RR)+abs(R1-a[i].r)+a[i].r-a[i].l);
        }
        LL=a[i].l;
        RR=a[i].r;
//        cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
    }
    cout<<sum+min(dp[R][1],dp[R][0])<<endl;
    return 0;
}