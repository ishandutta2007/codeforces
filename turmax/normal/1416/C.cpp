#include <bits/stdc++.h>

using namespace std;
#define int long long
int cur[32];
void go(vector <int> a,int m)
{
    if(m==(-1))
    {
        return;
    }
    if(a.size()<=1)
    {
        return;
    }
    vector <int> v0,v1;
    vector <int> z0,z1;
    int n=a.size();
    for(int i=0;i<n;++i)
    {
        if(a[i] & (1<<m))
        {
            v1.push_back(a[i]);
            z1.push_back(i);
        }
        else
        {
            v0.push_back(a[i]);
            z0.push_back(i);
        }
    }
    sort(z1.begin(),z1.end());
    int c=0;
    for(auto h:z0)
    {
        c+=(lower_bound(z1.begin(),z1.end(),h)-z1.begin());
    }
    cur[m]+=(((int)z0.size())*((int) z1.size())-2*c);
    if(!v0.empty())
    go(v0,m-1);
    if(!v1.empty())
    go(v1,m-1);
}
int go1(vector <int> b)
{
    vector <int> v1,v2;
    int n=b.size();
    if(n<=1) return 0;
    if(n==2)
    {
        if(b[0]<=b[1])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    for(int i=0;i<n/2;++i)
    {
        v1.push_back(b[i]);
    }
    for(int i=n/2;i<n;++i)
    {
        v2.push_back(b[i]);
    }
    vector <int> z2=v2;
    sort(v2.begin(),v2.end());
    int c=0;
    for(auto h:v1)
    {
        c+=(lower_bound(v2.begin(),v2.end(),h)-v2.begin());
    }
    return c+go1(v1)+go1(z2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    go(a,30);
    int x=0;
    for(int i=0;i<32;++i)
    {
        if(cur[i]<0)
        {
            x+=(1<<i);
        }
    }
    vector <int> b(n);
    for(int i=0;i<n;++i)
    {
        b[i]=a[i]^x;
    }
    cout<<go1(b)<<' '<<x;
    return 0;
}