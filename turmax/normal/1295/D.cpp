#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1)
    {
        v.push_back(x);
    }
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
int eul(int n)
{
    vector <int> v=rasl(n);
    int ans=n;
    map <int,int> o;
    for(int i=0;i<v.size();++i)
    {
        if(!o.count(v[i]))
        {
            ans/=v[i];
            ans*=(v[i]-1);
            o[v[i]]=1;
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
    int a,m;
    cin>>a>>m;
    int x=__gcd(a,m);
    int t=(m/x);
    //cout<<t<<" t "<<endl;
    cout<<eul(t)<<endl;
    }
    return 0;
}