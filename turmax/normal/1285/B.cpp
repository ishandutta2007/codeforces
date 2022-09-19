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
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int s=0;
    bool h=false;
    for(int i=0;i<n;++i)
    {
        s+=a[i];
        if(s<=0)
        {
            cout<<"NO"<<endl;
            h=true;
            break;
        }
    }
    if(h)
    {
        continue;
    }
    s=0;
    h=false;
    for(int i=0;i<n;++i)
    {
        s+=a[n-i-1];
        if(s<=0)
        {
            cout<<"NO"<<endl;
            h=true;
            break;
        }
    }
    if(h)
    {
        continue;
    }
    cout<<"YES"<<endl;
    }
    return 0;
}