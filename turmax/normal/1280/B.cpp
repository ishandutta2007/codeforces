#include <bits/stdc++.h>

using namespace std;
#define int long long
bool go(vector <char> v)
{
    bool ans=true;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]=='P')
        {
            ans=false;
        }
    }
    return ans;
}
bool to(vector <char> v)
{
    bool ans=false;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]=='A')
        {
            ans=true;
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,m;
    cin>>n>>m;
    vector <vector <char> > a(n);
    vector <vector <char> > b(m);
    char s;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>s;
            if(s=='A')
            {
                ++sum;
            }
            a[i].push_back(s);
            b[j].push_back(s);
        }
    }
    if(sum==0)
    {
        cout<<"MORTAL"<<endl;
        continue;
    }
    else if(sum==(n*m))
    {
        cout<<0<<endl;
        continue;
    }
    int ans=4;
    if(to(a[0]) || to(a[n-1]))
    {
        ans=3;
    }
    vector <char> v;
    for(int i=0;i<n;++i)
    {
        v.push_back(a[i][0]);
    }
    if(to(v))
    {
        ans=3;
    }
    v.clear();
    for(int i=0;i<n;++i)
    {
        v.push_back(a[i][m-1]);
    }
    if(to(v))
    {
        ans=3;
    }
    if(a[0][0]=='A' || a[n-1][0]=='A' || a[n-1][m-1]=='A' || a[0][m-1]=='A')
    {
        ans=2;
    }
    for(int i=0;i<n;++i)
    {
        if(go(a[i]))
        {
            ans=2;
        }
    }
    for(int i=0;i<m;++i)
    {
        if(go(b[i]))
        {
            ans=2;
        }
    }
    if(go(a[0]) || go(a[n-1]))
    {
        ans=1;
    }
    bool h=true;
    for(int i=0;i<n;++i)
    {
        if(a[i][0]=='P')
        {
            h=false;
        }
    }
    if(h)
    {
        ans=1;
    }
    h=true;
    for(int i=0;i<n;++i)
    {
        if(a[i][m-1]=='P')
        {
            h=false;
        }
    }
    if(h)
    {
        ans=1;
    }
    cout<<ans<<endl;
    }
    return 0;
}