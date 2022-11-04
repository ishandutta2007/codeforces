#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const ll Mod=1e9+7;
int a[200005],b[200005],c[200005],va[200005],vb[200005],vc[200005];
int dp[200005][5];
int main()
{
    sync;
    int aa,bb,cc;
    cin>>aa>>bb>>cc;
    int n=aa+bb+cc;
    for(int i=1;i<=n;i++)
    {
        va[i]=1;
        vb[i]=1;
        vc[i]=1;
    }
    for(int i=1;i<=aa;i++)
    {
        cin>>a[i];
        va[a[i]]=0;
    }
    for(int i=1;i<=bb;i++)
    {
        cin>>b[i];
        vb[b[i]]=0;
    }
    for(int i=1;i<=cc;i++)
    {
        cin>>c[i];
        vc[c[i]]=0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=dp[i-1][1]+va[i];
        dp[i][2]=min(dp[i-1][1]+vb[i],dp[i-1][2]+vb[i]);
        dp[i][3]=min(min(dp[i-1][1]+vc[i],dp[i-1][2]+vc[i]),dp[i-1][3]+vc[i]);
    }
    cout<<min(min(dp[n][1],dp[n][2]),dp[n][3])<<endl;
    return 0;
}