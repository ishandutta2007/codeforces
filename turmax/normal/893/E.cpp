#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
const int maxn=2000000;
int fact[maxn+1];
int invf[maxn+1];
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
int inv(int x)
{
    return po(x,p-2);
}
int c(int n,int k)
{
    int ans=1;
    ans*=fact[n];
    ans*=invf[k];
    ans%=p;
    ans*=invf[n-k];
    ans%=p;
    return ans;
}
int razb(int n,int k)
{
    return c(n+k-1,k-1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<=maxn;++i)
    {
        fact[i]=u;
        invf[i]=inv(fact[i]);
        u*=(i+1);
        u%=p;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        vector <int> v=rasl(x);
        map <int,int> u;
        for(int i=0;i<v.size();++i)
        {
            if(!u.count(v[i]))
            {
                u[v[i]]=1;
            }
            else
            {
                u[v[i]]++;
            }
        }
        set <int> h;
        int ans=1;
        for(int i=0;i<v.size();++i)
        {
            if(!h.count(v[i]))
            {
                ans*=razb(u[v[i]],y);
                ans%=p;
            }
            h.insert(v[i]);
        }
        ans*=po(2,y-1);
        ans%=p;
        cout<<ans<<endl;
    }
    return 0;
}