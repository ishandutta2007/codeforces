#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,s;
    cin>>n>>s;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int r=0;
    int ma=(-1e18);
    int ans;
    int num=0;
    for(int i=0;i<n;++i)
    {
        r+=a[i];
        if(a[i]>ma)
        {
            num=i;
            ma=a[i];
        }
        if((r-ma)<=s)
        {
            ans=num;
        }
    }
    if(r<=s)
    {
        ans=(-1);
    }
    cout<<(ans+1)<<endl;
    }
    return 0;
}