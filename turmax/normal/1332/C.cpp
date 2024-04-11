#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector <int> v)
{
    map <int,int> u;
    vector <int> keys;
    int n=v.size();
    for(int i=0;i<n;++i)
    {
        int x=v[i];
        if(!u.count(x))
        {
            u[x]=1;
            keys.push_back(x);
        }
        else
        {
            u[x]++;
        }
    }
    int ma=0;
    for(int i=0;i<keys.size();++i)
    {
        ma=max(ma,u[keys[i]]);
    }
    return v.size()-ma;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector <int> v;
    int ans=0;
    for(int i=0;i<=((k-1)/2);++i)
    {
        v.clear();
        for(int j=i;j<n;j+=k)
        {
            v.push_back(s[j]);
        }
        if((k-1-i)!=i)
        {
        for(int j=(k-1-i);j<n;j+=k)
        {
            v.push_back(s[j]);
        }
        }
        ans+=go(v);
    }
    cout<<ans<<endl;
    }
    return 0;
}