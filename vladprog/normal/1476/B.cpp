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
        int n,k;
        cin>>n>>k;
        int sum;
        cin>>sum;
        int ans=0;
        for(int i=1;i<=n-1;i++)
        {
            int pi;
            cin>>pi;
            int need=(100*pi+k-1)/k;
            if(sum<need)
                ans+=need-sum,
                sum=need;
            sum+=pi;
        }
        cout<<ans<<"\n";
    }
}