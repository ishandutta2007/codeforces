#include <bits/stdc++.h>

using namespace std;
#define int long long
int mex(vector <int> v)
{
    int n=v.size()+1;
    bool used[n];
    for(int i=0;i<n;++i) used[i]=false;
    for(int i=0;i<v.size();++i)
    {
        used[v[i]]=true;
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            return i;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n];
    vector <int> v(n);
    for(int i=0;i<n;++i) {cin>>a[i];v[i]=a[i];}
    vector <int> res;
    while(true)
    {
        int m=mex(v);
        if(m==n)
        {
            break;
        }
        res.push_back(m);
        a[m]=m;
        v[m]=m;
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]!=i)
        {
            res.push_back(i);
            a[i]=n;
            v[i]=n;
            while(true)
            {
            int m=mex(v);
            if(m==n)
            {
                break;
            }
            res.push_back(m);
            a[m]=m;
            v[m]=m;
        }
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]+1<<' ';
    }
    cout<<endl;
    }
    return 0;
}