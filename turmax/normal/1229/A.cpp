#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[61];
bool maz(int x,int y)
{
    if(y==0)
    {
        return true;
    }
    if(x%2==0 && y%2==1)
    {
        return false;
    }
    return maz(x/2,y/2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int u=1;
    for(int i=0;i<61;++i)
    {
        po[i]=u;
        u*=2;
    }
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    int k;
    map <int,int> m;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a[i]=k;
        if(m.count(a[i])==0)
        {
            m[a[i]]=1;
        }
        else
        {
            m[a[i]]++;
        }
    }
    vector <int> c;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        b[i]=k;
    }
    for(int i=0;i<n;++i)
    {
        if(m[a[i]]>=2)
        {
            c.push_back(a[i]);
        }
    }
    int o;
    if(!c.empty())
    {
    for(int i=0;i<n;++i)
    {
        o=c.size();
        for(int j=0;j<o;++j)
        {
            if(maz(c[j],a[i]))
            {
                c.push_back(a[i]);
                break;
            }
        }
    }
    }
    map <int,bool> w;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        w[a[i]]=false;
    }
    for(int i=0;i<c.size();++i)
    {
        w[c[i]]=true;
    }
    for(int i=0;i<n;++i)
    {
        if(w[a[i]])
        {
            sum+=b[i];
        }
    }
    cout<<sum;
    return 0;
}