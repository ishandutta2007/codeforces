#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        int u=(a+b-n)/2;
        if((a+b-x-y)<=n)
        {
            cout<<x*y<<endl;
            continue;
        }
        if(a>=(x+n) && b>=(y+n))
        {
            cout<<min((a-n)*b,(b-n)*a)<<endl;
            continue;
        }
        int ans=1e18;
        if(a<=(x+n)) ans=min(ans,x*(a+b-x-n));
        else ans=min(ans,(a-n)*b);
        if(b<=(y+n)) ans=min(ans,y*(a+b-y-n));
        else ans=min(ans,(b-n)*a);
        cout<<ans<<endl;
    }
    return 0;
}