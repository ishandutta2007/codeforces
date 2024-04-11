#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cycle=0;cycle<q;++cycle)
    {
    int n;
    int z;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    z=n/2;
    int curr=0;
    int l=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==a[0])
        {
            ++l;
        }
        else
        {
            break;
        }
    }
    curr=l;
    reverse(a.begin(),a.end());
    int d=n-2*l-1;
    if(d<0)
    {
        cout<<0<<" "<<0<<" "<<0<<endl;
        continue;
    }
    int z1=lower_bound(a.begin(),a.end(),a[d])-a.begin();
    if((n-z1)>z)
    {
        cout<<0<<" "<<0<<" "<<0<<endl;
        continue;
    }
    int r=upper_bound(a.begin(),a.end(),a[(n-1)/2])-a.begin();
    if((z1-r)>l)
    {
        cout<<l<<" "<<((n-z1-l))<<" "<<(z1-r)<<endl;
        continue;
    }
    else
    {
        cout<<0<<" "<<0<<" "<<0<<endl;
        continue;
    }
    }
    return 0;
}