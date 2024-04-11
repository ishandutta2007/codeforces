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
    vector <int> v;
    map <int,int> u;
    int o;
    for(int i=1;i<50000;++i)
    {
        o=(n/i);
        if(!u.count(o))
        {
            v.push_back(o);
            u[o]=1;
        }
    }
    for(int i=1;i<50000;++i)
    {
        if((n/i)!=0 && (n/(n/i))==i)
        {
            if(!u.count(i))
            {
                v.push_back(i);
                u[i]=1;
            }
        }
    }
    if(!u.count(0))
    {
        v.push_back(0);
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}