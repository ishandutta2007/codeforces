#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

int a[N],dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<h;i++)
        dp[0][i]=-1e9;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<h;j++)
            dp[i][j]=max(dp[i-1][(j-a[i]+h)%h],
                         dp[i-1][(j-(a[i]-1)+h)%h])+
                     (l<=j&&j<=r),
            ans=max(ans,dp[i][j]);
    cout<<ans;
}