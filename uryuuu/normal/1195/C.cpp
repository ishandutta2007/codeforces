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
const int maxn=100005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;
 
ll a[maxn],b[maxn],dp[maxn][5];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    dp[1][1]=a[1];
    dp[1][2]=b[1];
//    cout<<dp[1][1]<<' '<<dp[1][2]<<endl;
    for(int i=2;i<=n;i++)
    {
        dp[i][2]=1ll*max(max(dp[i-1][1],dp[i-2][2])+b[i],dp[i-1][2]);
        dp[i][1]=1ll*max(max(dp[i-1][2],dp[i-2][1])+a[i],dp[i-1][1]);
//        cout<<dp[i][1]<<' '<<dp[i][2]<<endl;
    }
    cout<<max(dp[n][2],dp[n][1])<<endl;
    return 0;
}