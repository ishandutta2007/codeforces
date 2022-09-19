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
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s%2==1)
    {
        cout<<"YES"<<endl;
        continue;
    }
    bool h=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
        if(!h)
        {
            break;
        }
        if((a[i]+a[j])&1)
        {
            cout<<"YES"<<endl;
            h=false;
        }
        }
    }
    if(h)
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}