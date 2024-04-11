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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int ans1=0,ans2=0;
        for(int i=0;i<(n-1);++i)
        {
            if((a[i+1]-a[i])>=0)
            {
               ans2+=(a[i+1]-a[i]);
            }
            else
            {
                ans1+=(a[i]-a[i+1]);
            }
        }
        if(ans1<=a[0] && ans2<=a[n-1])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}