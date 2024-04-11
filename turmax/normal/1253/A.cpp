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
    cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector <int> c(n);
    int l=1e18,r=(-1);
    for(int i=0;i<n;++i)
    {
        c[i]=b[i]-a[i];
    }
    for(int i=0;i<n;++i)
    {
        if(c[i]!=0)
        {
            l=min(l,i);
            r=i;
        }
    }
    if(l==1e18)
    {
        cout<<"YES"<<endl;
        continue;
    }
    int u=b[l]-a[l];
    if(u<0)
    {
        cout<<"NO"<<endl;
        continue;
    }
    bool h;
    h=true;
    for(int i=l;i<=r;++i)
    {
        if((b[i]-a[i])!=u)
        {
            cout<<"NO"<<endl;
            h=false;
            break;
        }
    }
    if(h)
    cout<<"YES"<<endl;
    }
    return 0;
}