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
    int lst=(n-1);
    int curr=a[n-1];
    while(lst>=1)
    {
        lst--;
        if(a[lst]>=curr)
        {
            curr=a[lst];
        }
        else
        {
            ++lst;
            break;
        }
    }
    //cout<<lst<<" lst "<<endl;
    int res=lst;
    for(int i=(lst-1);i>=0;i--)
    {
        if(a[i]<=a[i+1])
        {
            res--;
        }
        else
        {
            break;
        }
    }
    cout<<res<<endl;
    }
    return 0;
}