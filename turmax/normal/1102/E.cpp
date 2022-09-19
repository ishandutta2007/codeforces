#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map <ll,ll> v;
vector <ll> a;
ll solve(ll f,ll n)
{
    if(f==(n-1))
    {
        return 1;
    }
    ll o=(-1);
    for(ll i=f;i<n;++i)
    {
        o=max(o,v[a[i]]);
        if(i==(n-1))
        {
            return 1;
        }
        if(o==i)
        {
            return(((solve(i+1,n))*2)%998244353);
        }
    }
    return 1;
}
int main()
{
    #define int long long
    int n,t;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>t;
        if(v.count(t)==0)
        {
            v[t]=i;
        }
        else
        {
            v[t]=max(v[t],i);
        }
        a.push_back(t);
    }
    cout<<solve(0,n);
    return 0;
}