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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


int l[maxn],r[maxn],x[maxn],pre[maxn],cnt[maxn];
ll dp[maxn],sum[maxn];
int main()
{
    sync;
    int n,m,k;
    cin>>n>>k>>m;
    for(int i=1;i<=m;i++)
        cin>>l[i]>>r[i]>>x[i];
    ll ans=1ll;
    for(int d=0;d<k;d++)
    {
        mm(pre);
        mm(sum);
        mm(dp);
        mm(cnt);
        for(int j=1;j<=m;j++)
        {
            if((x[j]>>d)&1)
            {
                cnt[l[j]]++;
                cnt[r[j]+1]--;
            }
            else
                pre[r[j]+1]=max(pre[r[j]+1],l[j]);
        }
        for(int i=1;i<=n+1;i++)
        {
            pre[i]=max(pre[i],pre[i-1]);
        }
        sum[0]=dp[0]=1;
        for(int i=1;i<=n+1;i++)
        {
            cnt[i]+=cnt[i-1];
//            cout<<cnt[i]<<' ';
            if(cnt[i])
            {
                dp[i]=0;
            }
            else
            {
                dp[i]=sum[i-1];
                if(pre[i])
                {
                    dp[i]=(dp[i]-sum[pre[i]-1]+Mod)%Mod;
                }
            }
            sum[i]=(sum[i-1]+dp[i])%Mod;
        }
        ans=1ll*ans*dp[n+1]%Mod;
    }
    cout<<ans<<endl;
    return 0;
}