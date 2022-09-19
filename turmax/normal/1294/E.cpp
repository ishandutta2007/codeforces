#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector <int> a,vector <int> b)
{
    int n=a.size();
    /*for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    vector <int> c;
    map <int,int> d2;
    for(int i=0;i<n;++i)
    {
        d2[b[i]]=i;
    }
    for(int i=0;i<n;++i)
    {
        if(!d2.count(a[i]))
        {
            c.push_back(1e18);
        }
        else
        {
            c.push_back((n+i-d2[a[i]])%n);
        }
    }
    sort(c.begin(),c.end());
    int res=1e18;
    for(int i=0;i<n;++i)
    {
        res=min(res,(int) (i+n-(upper_bound(c.begin(),c.end(),i)-lower_bound(c.begin(),c.end(),i))));
    }
    //cout<<res<<endl;
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <vector <int> > b(n);
    int x;
    for(int i=0;i<n;++i)
    {
        vector <int> v;
        for(int j=0;j<m;++j)
        {
            cin>>x;
            x--;
            v.push_back(x);
        }
        b[i]=v;
    }
    vector <vector <int> > a(m);
    for(int i=0;i<m;++i)
    {
        a[i].resize(n);
        for(int j=0;j<n;++j)
        {
            a[i][j]=b[j][i];
        }
    }
    vector <vector <int> > to(m);
    for(int i=0;i<m;++i)
    {
        to[i].resize(n);
        for(int j=0;j<n;++j)
        {
            to[i][j]=(i+j*m);
        }
    }
    int ans=0;
    for(int i=0;i<m;++i)
    {
        ans+=go(a[i],to[i]);
    }
    cout<<ans;
    return 0;
}