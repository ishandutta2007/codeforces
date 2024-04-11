#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    int ans=0;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    for(int i=0;i<n;++i) ans+=(a[i]*b[i]);
    int res=ans;
    for(int mid=1;mid<(2*n);++mid)
    {
        if(mid%2==0)
        {
            int val=0;
            for(int i=(mid/2-1);i>=0 && (mid-i)<n;i--)
            {
                val-=(a[i]-a[mid-i])*(b[i]-b[mid-i]);
                res=max(res,ans+val);
            }
        }
        else
        {
            int val=0;
            for(int i=(mid/2);i>=0 && (mid-i)<n;i--)
            {
                val-=(a[i]-a[mid-i])*(b[i]-b[mid-i]);
                res=max(res,ans+val);
            }
        }
    }
    cout<<res;
    return 0;
}