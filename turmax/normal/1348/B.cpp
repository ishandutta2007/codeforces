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
    int n,k;
    cin>>n>>k;
    int a[n];
    set <int> u;
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(!u.count(a[i]))
        {
            v.push_back(a[i]);
        }
        u.insert(a[i]);
    }
    if(u.size()>k)
    {
        cout<<(-1)<<endl;
        continue;
    }
    while(v.size()<k)
    {
        v.push_back(1);
    }
    cout<<n*k<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<k;++j)
        {
            cout<<v[j]<<" ";
        }
    }
    cout<<endl;
    }
    return 0;
}