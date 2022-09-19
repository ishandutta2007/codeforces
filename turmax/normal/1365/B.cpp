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
    int b[n];
    for(int i=0;i<n;++i) cin>>b[i];
    set <int> o;
    for(int i=0;i<n;++i) o.insert(b[i]);
    if(o.size()==2)
    {
        cout<<"Yes"<<endl;
        continue;
    }
    bool h=true;
    for(int i=0;i<(n-1);++i)
    {
        if(a[i+1]<a[i])
        {
            h=false;
        }
    }
    if(h)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    return 0;
}