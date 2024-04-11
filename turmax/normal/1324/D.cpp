#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int c[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        c[i]=a[i]-b[i];
    }
    int ans=0;
    int h=0;
    sort(c,c+n);
    for(int i=0;i<n;++i)
    {
        ans+=(c+n-upper_bound(c,c+n,-c[i]));
        if(c[i]>0)
        {
            ++h;
        }
    }
    cout<<(ans-h)/2;
    return 0;
}