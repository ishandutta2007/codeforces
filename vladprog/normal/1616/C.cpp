#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

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
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans=max(0ll,n-2);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int res=0;
                for(int k=0;k<n;k++)
                    res+=(a[i]-a[j])*(i-k)!=(a[i]-a[k])*(i-j);
                ans=min(ans,res);
            }
        cout<<ans<<"\n";
    }
}