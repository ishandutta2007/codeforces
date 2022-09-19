#include <bits/stdc++.h>

using namespace std;
#define int long long
int o[1000001];
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
    vector <int> v;
    v.push_back(0);
    o[0]=0;
    for(int i=1;i<=n;++i)
    {
        o[i]=(-1);
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int curr=0;
    int z;
    int l;
    while(true)
    {
        z=(n-curr-1);
        curr+=a[z];
        v.push_back(z);
        if(o[curr]!=(-1))
        {
            l=o[curr];
            break;
        }
        o[curr]=v.size()-1;
    }
    cout<<v.size()-l-1<<'\n';
    for(int i=(l+1);i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    cout<<'\n';
    }
    return 0;
}