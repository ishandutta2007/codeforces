#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int a[N];
int dp[N][N];
int mex[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int l=1;l<=n;l++)
        {
            set<int> s;
            for(int r=l;r<=n;r++)
            {
                s.insert(a[r]);
                mex[l][r]=0;
                while(s.count(mex[l][r]))
                    mex[l][r]++;
            }
        }
        int ans=0;
        for(int len=1;len<=n;len++)
            for(int l=1;l+len-1<=n;l++)
            {
                int r=l+len-1;
                dp[l][r]=mex[l][r]+1;
                for(int i=l;i<=r-1;i++)
                    dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
                ans+=dp[l][r];
//                cout<<l<<" "<<r<<" -> "<<dp[l][r]<<endl;
            }
        cout<<ans<<"\n";
    }
}