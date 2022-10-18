#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int dp[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        string a;
        cin>>a;
        a="_"+a;
        int x,y;
        cin>>x>>y;
        for(int i=n;i>=1;i--)
        {
            dp[i]=a[i]=='0';
            if(i+k<=n)
                dp[i]+=dp[i+k];
        }
        int ans=1e18;
        for(int i=p;i<=n;i++)
            ans=min(ans,dp[i]*x+(i-p)*y);
        cout<<ans<<"\n";
    }
}