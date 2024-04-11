#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxa=1000001;
int u[maxa];
int eu[maxa];
int f[maxa];
vector <int> di1[maxa];
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
vector <int> di(int x)
{
    vector <int> res;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            if(i*i==x)
            {
                res.push_back(i);
            }
            else
            {
                res.push_back(i);
                res.push_back(x/i);
            }
        }
    }
    return res;
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1)
    {
        return v;
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
int eul(int x)
{
    vector <int> v=rasl(x);
    set <int> z;
    int ans=1;
    for(int i=0;i<v.size();++i)
    {
        if(!z.count(v[i]))
        {
            ans*=(v[i]-1);
        }
        else
        {
            ans*=v[i];
        }
        z.insert(v[i]);
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<maxa;++i)
    {
        for(int j=1;(i*j)<maxa;++j)
        {
            di1[i*j].push_back(i);
        }
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        vector <int> v=di1[a[i]];
        for(int i=0;i<v.size();++i)
        {
            u[v[i]]++;
        }
    }
    int ans=0;
    f[1]=0;
    for(int i=2;i<maxa;++i)
    {
        vector <int> v=di1[i];
        int sum=0;
        for(int j=0;j<v.size();++j)
        {
             sum+=f[v[j]];
        }
        f[i]=(i-sum);
        int h=f[i];
        int z=u[i];
        if(z)
        ans+=(((h*(po(2,z-1)))%p)*z);
        ans%=p;
    }
    cout<<ans;
    return 0;
}