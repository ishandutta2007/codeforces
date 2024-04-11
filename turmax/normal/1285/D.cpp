#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(vector <int> v,int t)
{
    if(v.size()==0)
    {
        return 0;
    }
    if(t==(-1))
    {
        return 0;
    }
    vector <int> v1;
    vector <int> v2;
    int g=(1<<t);
    int n=v.size();
    for(int i=0;i<n;++i)
    {
        if(v[i] & g)
        {
            v1.push_back(v[i]);
        }
        else
        {
            v2.push_back(v[i]);
        }
    }
    if(v1.empty())
    {
        return slv(v2,t-1);
    }
    else if(v2.empty())
    {
        return slv(v1,t-1);
    }
    return min(slv(v1,t-1),slv(v2,t-1))+g;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<slv(a,30);
    return 0;
}