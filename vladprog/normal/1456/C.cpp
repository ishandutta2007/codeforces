#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100;

int c[N],dp[N],suff1[N],suff2[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    sort(c+1,c+n+1);
    for(int i=n;i>=1;i--)
        suff1[i]=suff1[i+1]+c[i];
    for(int i=n;i>=1;i--)
        suff2[i]=suff2[i+1]+suff1[i+1];
    int mid=0;
    for(int i=1;i<=n;i++)
        if(c[i]<0)
            mid=i,
            dp[i]=dp[i-1]+(i-1)/k*c[i];
    int ans=-1e18;
    for(int i=1;i<=mid+1;i++)
        ans=max(ans,(i-1)/k*suff1[i]+suff2[i]+dp[i-1]);
    cout<<ans;
}