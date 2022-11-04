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
const double pi=acos(-1);
const int maxn=2005;
//const ll Mod=1000000007;
 

int a[maxn],b[maxn],c[maxn];
ll dp[maxn][maxn];
int n,h,L,R;
bool pd(int x)
{
    if(x>=L&&x<=R)
        return 1;
    return 0;
}

int main()
{
    sync;
    cin>>n>>h>>L>>R;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=h;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=h;j++)
        {
            dp[i][j]=-1;
        }
    }
    if(pd(a[1]))
        dp[1][a[1]]=1;
    else
        dp[1][a[1]]=0;
    int d=(a[1]-1+h)%h;
    if(pd(d))
        dp[1][d]=1;
    else
        dp[1][d]=0;
    
    int l,r;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<h;j++)
        {
            
            l=(j+h+h-a[i]+1)%h;
            r=(j+h+h-a[i])%h;
            if(dp[i-1][r]!=-1||dp[i-1][l]!=-1)
                dp[i][j]=max(dp[i-1][l],dp[i-1][r]);
//            if(i==4&&j==20)
//                cout<<dp[i][j]<<' '<<l<<' '<<r<<endl;
            if(dp[i][j]!=-1&&pd(j))
            {
                dp[i][j]++;
            }
        }
    }
    ll zd=0;
    for(int i=0;i<h;i++)
    {
        zd=max(dp[n][i],zd);
    }
    cout<<zd<<endl;
    return 0;
}