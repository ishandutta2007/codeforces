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
//#include <chrono>
//#include <random>
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
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;


int sq[maxn];
int a[maxn];
unordered_map<int,int>cnt;
int mnleft[maxn][21],dp[maxn][21];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    int num=0;
    for(int i=2;i<maxn;i++)
    {
        if(i*i>10000000)
            break;
        sq[++num]=i*i;
    }
    int i,j;
    while(t--)
    {
        int x;
        int k;
        cin>>n>>k;
        cnt.clear();
        for(i=1;i<=n;i++)
        {
            cin>>x;
            for(j=1;j<=num;j++)
            {
                if(sq[j]>x)
                    break;
                while(x%sq[j]==0)
                {
                    x/=sq[j];
                }
            }
            a[i]=x;
        }
        
        for(int j=0;j<=k;j++)
        {
            int L=n+1,now=0;
            for(int i=n;i>=1;i--)
            {
                while(L-1>=1&&now+(cnt[a[L-1]]>0)<=j)
                {
                    L--;
                    now+=(cnt[a[L]]>0);
                    cnt[a[L]]++;
                }
                mnleft[i][j]=L;
                if(cnt[a[i]]>1)
                    now--;
                cnt[a[i]]--;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                dp[i][j]=inf;
        }
        
        for(int i=0;i<=k;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j>0)
                    dp[i][j]=dp[i][j-1];
                for(int lst=0;lst<=j;lst++)
                {
                    dp[i][j]=min(dp[i][j],dp[mnleft[i][lst]-1][j-lst]+1);
                }
            }
        }
        int ans=inf;
        for(int i=0;i<=k;i++)
        {
            ans=min(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}