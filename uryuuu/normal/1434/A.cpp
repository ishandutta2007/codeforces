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
//const ll Mod=1000000007;
const ll Mod = 998244353;


ll a[10],b[maxn];

ll c[maxn][7];

struct node
{
    ll val,id;
}dp[maxn*6];

int vis[maxn];

bool cmp(node a,node b)
{
    return a.val<b.val;
}

int main()
{
    sync;
    int n;
    for(int i=1;i<=6;i++)
        cin>>a[i];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+7);
    sort(b+1,b+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            c[i][j]=b[i]-a[j];
            dp[++cnt].val=c[i][j];
            dp[cnt].id=i;
        }
    }
    
    sort(dp+1,dp+cnt+1,cmp);
    int L=2,R=1;
    int num=0;
    ll ans=2e16;
    for(R=1;R<=cnt;R++)
    {
        if(vis[dp[R].id]==0)
        {
            num++;
        }
        vis[dp[R].id]++;
        if(num==n)
            break;
    }
    ans=min(ans,dp[R].val-dp[1].val);
 
    while(L<=cnt)
    {
        if(vis[dp[L-1].id]==1)
        {
            num--;
        }
        vis[dp[L-1].id]--;
        if(num<n)
        {
            R++;
            for(;R<=cnt;R++)
            {
                if(vis[dp[R].id]==0)
                {
                    num++;
                }
                vis[dp[R].id]++;
                if(num==n)
                    break;
            }
            if(num<n)
                break;
        }
        ans=min(ans,dp[R].val-dp[L].val);
        L++;
    }
    cout<<ans<<endl;
    return 0;
}