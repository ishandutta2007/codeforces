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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int n;
ll a[maxn];
ll dp[maxn][3],dep[maxn][3];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dp[1][0]=a[1];
        dp[1][1]=a[1];
        dp[1][2]=a[1];
        int m=1;
        ll ans=0;
        for(int i=3;i<=n;i+=2)
        {
            dp[i][0]=dp[i-2][0]+a[i];
            dp[i][1]=max(dp[i-2][0],dp[i-2][1])+a[i-1];
            dp[i][2]=max(dp[i-2][1],dp[i-2][2])+a[i];
            m=i;
        }
        ans=max(max(dp[m][0],dp[m][1]),dp[m][2]);
        
        
        
        int h=0;
        for(int i=2;i<=n;i+=2)
        {
            dep[i][0]=dep[i-2][0]+a[i-1];
            dep[i][1]=max(dep[i-2][0],dep[i-2][1])+a[i];
            dep[i][2]=max(dep[i-2][1],dep[i-2][2])+a[i-1];
            h=i;
        }
        
        if(m==n)
            ans=max(ans,max(max(dep[h][0],dep[h][1]),dep[h][2])+a[n]);
        else
            ans=max(ans,max(max(dep[h][0],dep[h][1]),dep[h][2]));
        
        
        cout<<ans<<endl;
    }
    return 0;
}