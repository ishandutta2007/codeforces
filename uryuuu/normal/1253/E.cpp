#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int dp[100][maxn];
 
struct node
{
    int p,s;
}a[100];
bool cmp(node a,node b)
{
    return a.p+a.s<b.p+b.s;
}
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].p>>a[i].s;
    }
    sort(a+1,a+n+1,cmp);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i].p<<' '<<a[i].s<<endl;
//    }
    memset(dp,inf,sizeof(dp));
    for(int i=1;i<=m;i++)
    {
        dp[1][i]=max(0,max(abs(i-a[1].p),abs(a[1].p-1))-a[1].s);
    }
//    cout<<dp[1][m]<<endl;
    int d;
    int dd;
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=max(0,max(a[i].p-a[i].s-1,m-(a[i].p+a[i].s)));j++)
        {
            int l=a[i].p-a[i].s-j-1;
            int cur=j;
            if(l>0)
                cur+=dp[i-1][l];
            dp[i][min(m,a[i].p+a[i].s+j)]=min(dp[i][min(m,a[i].p+a[i].s+j)],cur);
        }
        dp[i][m] = min(dp[i][m],dp[i-1][m]);
        for (int j=m-1;j>=0;j--) dp[i][j] = min(min(dp[i][j],dp[i-1][j]),dp[i][j+1]);
    }
//    cout<<endl;
    cout<<dp[n][m]<<endl;
    return 0;
}