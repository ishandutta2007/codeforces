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
typedef vector<int> vi;
const double pi=acos(-1);
const int maxn=2005;
//const ll Mod=1000000007;
const ll Mod=998244353;
ll dp[maxn][maxn];
ll sum[maxn];
char s[maxn];
ll p[maxn];
int main()
{
//    sync;
    p[0]=1;
    for(int i=1;i<=maxn;i++)
        p[i]=(p[i-1]*2)%Mod;
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
    mm(dp);
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l<=n+1-len;l++)
        {
            int r=l+len-1;
            if(s[l]!='(')
                dp[l][r]=(dp[l][r]+dp[l+1][r])%Mod;
            if(s[r]!=')')
                dp[l][r]=(dp[l][r]+dp[l][r-1])%Mod;
            if(s[l]!='('&&s[r]!=')')
                dp[l][r]=(dp[l][r]-dp[l+1][r-1]+Mod)%Mod;
            if(s[l]!=')'&&s[r]!='(')
            dp[l][r]=(dp[l][r]+dp[l+1][r-1]+p[sum[r-1]-sum[l]])%Mod;
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}