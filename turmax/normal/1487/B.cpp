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
        int n,k;
        cin>>n>>k;
        //(n%2==0)
        k--;
        if(n%2==0)
        {
            //(n,n-1,...)
            int ans=(k+1);
            ans%=n;ans+=n;ans%=n;
            if(ans==0) ans=n;
            cout<<ans<<endl;
        }
        else
        {
            //(n,n-1,...) (n+3)/2 (n-1)/2
            int per=(n-1)/2;
            int pl=(n+1)/2;
            int curr=1;
            curr+=(k/per)*pl;
            curr+=(k%per);
            int ans=curr;
            ans%=n;ans+=n;ans%=n;
            if(ans==0) ans=n;
            cout<<ans<<endl;
        }
    }
    return 0;
}