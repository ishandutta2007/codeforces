#include <bits/stdc++.h>

using namespace std;
#define int long long
multiset <int> rasl (int n)
{
    if(n==1)
    {
        multiset <int> u;
        return u;
    }
    for(int i=2;i<=sqrt(n)+2;++i)
    {
        if(n%i==0)
        {
            multiset <int> u=rasl(n/i);
            u.insert(i);
            return u;
        }
    }
    multiset <int> u;
    u.insert(n);
    return u;
}
int anspr(int n,int v)
{
    int u=v;
    int sum=0;
    while(u<=n)
    {
        sum+=(n/u);
        if(u>n/v)
        {
            break;
        }
        u*=v;
    }
    return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k=1e18;
    multiset <int> y=rasl(m);
    while(y.size()>0)
    {
        k=min(k,anspr(n,(*y.begin()))/y.count((*y.begin())));
        y.erase((*y.begin()));
    }
    cout<<k;
    return 0;
}