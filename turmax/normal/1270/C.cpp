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
    int n;
    cin>>n;
    vector <int> a(n);
    int t;
    t=0;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        t^=a[i];
        sum+=a[i];
    }
    cout<<2<<endl;
    cout<<t<<" ";
    sum+=t;
    cout<<sum<<endl;
    }
    return 0;
}