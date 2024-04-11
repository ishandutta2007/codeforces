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


int t[20],g[20],dp[1<<16][4];

int main()
{
    sync;
    int n,T;
    cin>>n>>T;
    for(int i=0;i<n;i++)
        cin>>t[i]>>g[i];
    dp[0][0]=1;
    ll cnt=0;
    for(int i=0;i<(1<<n);i++)
    {
        for(int k=0;k<4;k++)
        {
            for(int j=0;j<n;j++)
            {
                if(((i&(1<<j))==0)&&g[j]!=k)
                    dp[i|(1<<j)][g[j]]=(dp[i|(1<<j)][g[j]]+dp[i][k])%Mod;
            }
            int sum=0;
            for(int k=0;k<n;k++)
            {
                if((i&(1<<k))!=0)
                    sum+=t[k];
            }
            if(sum==T)
            {
                cnt+=dp[i][k];
                cnt%=Mod;
            }
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}