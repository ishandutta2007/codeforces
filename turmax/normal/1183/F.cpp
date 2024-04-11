#include <bits/stdc++.h>

using namespace std;
#define int long long
int go2(vector <int> a)
{
    if(a.size()==1)
    {
        return a[0];
    }
    if(a.size()==0)
    {
        return 0;
    }
    int n=a.size();
    vector <bool> used(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    int sum=a[0];
    for(int i=0;i<n;++i)
    {
        if((a[0]%a[i])==0)
        {
            used[i]=true;
        }
    }
    int l=(-1);
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            l=i;
            break;
        }
    }
    if(l==(-1))
    {
        return sum;
    }
    sum+=a[l];
    return sum;
}
int go(vector <int> a)
{
    int n=a.size();
    vector <int> v;
    vector <bool> used(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    reverse(a.begin(),a.end());
    int sum=a[0];
    for(int i=0;i<n;++i)
    {
        if((a[0]%a[i])==0)
        {
            used[i]=true;
        }
    }
    int l=(-1);
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            v.push_back(a[i]);
            l=i;
        }
    }
    if(l==(-1))
    {
        return sum;
    }
    int ma=go2(v);
    v.erase(v.begin());
    ma=max(ma,go2(v));
    sum+=ma;
    return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cycle=0;cycle<q;++cycle)
    {
    int n;
    cin>>n;
    vector <int> a;
    map <int,int> m;
    m.clear();
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        if(m.count(k)==0)
        {
            m[k]=1;
            a.push_back(k);
        }
    }
    sort(a.begin(),a.end());
    if(a.size()==1)
    {
        cout<<a[0]<<endl;
        continue;
    }
    int ma=go(a);
    a.erase(a.begin()+a.size()-1);
    ma=max(ma,go(a));
    if(a.size()==1)
    {
        cout<<ma<<endl;
        continue;
    }
    a.erase(a.begin()+a.size()-1);
    ma=max(ma,go(a));
    cout<<ma<<endl;
    }
    return 0;
}