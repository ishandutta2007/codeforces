#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > res;
vector <int> oper(vector <int> a,vector <int> d)
{
    for(int i=d.size()-1;i>=0;i--)
    {
        if(d[i]==0)
        {
            d.erase(d.begin()+i);
        }
    }
    if(d.size()==1) return a;
    res.push_back(d);
    int curr=0;
    for(auto h:d)
    {
        reverse(a.begin()+curr,a.begin()+curr+h);
        curr+=h;
    }
    reverse(a.begin(),a.end());
    return a;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=1;i<n;++i)
    {
        int l=1e18;
        int r=(-1);
        int pos;
        for(int j=0;j<n;++j)
        {
            if(a[j]<=i)
            {
                l=min(l,j);
                r=max(r,j);
            }
            if(a[j]==(i+1))
            {
                pos=j;
            }
        }
        vector <int> d;
        if(pos<l)
        {
            if(a[l]==1)
            {
               d.push_back(pos);
               d.push_back(l-pos);
               d.push_back(r-l+1);
               d.push_back(a.size()-r-1);
            }
            else
            {
                d.push_back(pos);
                d.push_back(l-pos);
                for(int i=l;i<=r;++i)
                {
                    d.push_back(1);
                }
                d.push_back(a.size()-r-1);
            }
        }
        else
        {
            if(a[l]==1)
            {
                d.push_back(l);
                for(int i=l;i<=r;++i)
                {
                    d.push_back(1);
                }
                d.push_back(pos-r);
                d.push_back(a.size()-pos-1);
            }
            else
            {
                d.push_back(l);
                d.push_back(r-l+1);
                d.push_back(pos-r);
                d.push_back(a.size()-pos-1);
            }
        }
        a=oper(a,d);
    }
    if(a[0]==n)
    {
        vector <int> d;
        for(int i=0;i<n;++i)
        {
            d.push_back(1);
        }
        a=oper(a,d);
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i].size()<<' ';
        for(auto h:res[i]) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}