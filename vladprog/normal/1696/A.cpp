#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,z;
        cin>>n>>z;
        int ans=0;
        while(n--)
        {
            int a;
            cin>>a;
            ans=max(ans,a|z);
        }
        cout<<ans<<"\n";
    }
}