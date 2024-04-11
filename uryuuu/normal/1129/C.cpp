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
const int maxn=3010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int n,a[maxn];
ll dp[maxn],ans,tr[maxn*maxn][2];

bool check(int i)
{
    if(a[i-3]==0&&a[i-2]==0&&a[i-1]==1&&a[i]==1)
        return 0;
    if(a[i-3]==0&&a[i-2]==1&&a[i-1]==0&&a[i]==1)
        return 0;
    if(a[i-3]==1&&a[i-2]==1&&a[i-1]==1&&a[i]==0)
        return 0;
    if(a[i-3]==1&&a[i-2]==1&&a[i-1]==1&&a[i]==1)
        return 0;
    return 1;
}

int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int rt=1,tot=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i+1]=1;
        rt=1;
        for(int j=i;j>=1;j--)
        {
            dp[j]=0;
            (dp[j]+=dp[j+1])%=Mod;
            (dp[j]+=dp[j+2])%=Mod;
            (dp[j]+=dp[j+3])%=Mod;
            if(check(j+3))
                (dp[j]+=dp[j+4])%=Mod;
            if(tr[rt][a[j]]==0)
            {
                tr[rt][a[j]]=++tot;
                ans=(1ll*ans+dp[j])%Mod;
            }
            rt=tr[rt][a[j]];
        }
        cout<<ans<<endl;
    }
    return 0;
}