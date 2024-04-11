#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q,x;
    cin>>q>>x;
    int a[x];
    set <int> d;
    for(int i=0;i<x;++i)
    {
        a[i]=i;
        d.insert(i);
    }
    int t;
    for(int i=0;i<q;++i)
    {
        cin>>t;
        d.erase(a[t%x]);
        a[t%x]+=x;
        d.insert(a[t%x]);
        cout<<(*d.begin())<<endl;
    }
    return 0;
}