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
//#include<unordered_map>
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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=300005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;


int a[maxn];

bool cmp(int a,int b)
{
    return a>b;
}

int vis[maxn],dp[maxn];

ll num;
ll prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn-5; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(1ll*i * prime[j]>maxn-5) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

int cnt=0;

struct node
{
    int val,k;
}b[105];

void dfs(int s,int pre,int st,int mx)
{
    if(s>=st+1)
    {
        if(pre!=mx)
            dp[pre]=max(dp[pre],dp[mx]+vis[pre]);
        return;
    }
    dfs(s+1,pre,st,mx);
    for(int i=1;i<=b[s].k;i++)
    {
        pre*=b[s].val;
        dfs(s+1,pre,st,mx);
    }
    return;
}


int main()
{
    sushu();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int nnn=n;
        mm(vis);
        mm(dp);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        sort(a+1,a+n+1,cmp);
        n=unique(a+1,a+n+1)-a-1;
        for(int i=1;i<=n;i++)
        {
            dp[a[i]]=vis[a[i]];
        }
        int d;
        for(int i=1;i<=n;i++)
        {
    //        cout<<a[i]<<' '<<dp[a[i]]<<endl;
            d=a[i];
            if(d==1)
                break;
            if(sf[d])
            {
                dp[1]=max(dp[1],dp[d]+vis[1]);
                continue;
            }
            cnt=0;
            for(int j=1;j<=num;j++)
            {
                if(sf[d])
                {
                    b[++cnt].val=d;
                    b[cnt].k=1;
                    break;
                }
                if(d%prime[j]==0)
                {
                    b[++cnt].val=prime[j];
                    b[cnt].k=0;
                    while(d%prime[j]==0)
                    {
                        b[cnt].k++;
                        d/=prime[j];
                    }
                }
                if(d==1)
                    break;
            }
            dfs(1,1,cnt,a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dp[a[i]]);
        }
        printf("%d\n",nnn-ans);
    }
    return 0;
}