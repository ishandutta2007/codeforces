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
    int b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    sort(a,a+n);sort(b,b+n);
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}