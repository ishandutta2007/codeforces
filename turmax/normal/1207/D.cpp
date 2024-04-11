#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=500000;
const int p=998244353;
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
int fact[maxn];
int invf[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u;
        invf[i]=inv(u);
        u*=(i+1);
        u%=p;
    }
    int n;
    cin>>n;
    int a[n];
    int b[n];
    vector <int> keys1;
    map <int,int> g1;
    vector <int> keys2;
    map <int,int> g2;
    vector <pair <int,int> > keys3;
    map <pair <int,int>,int> g3;
    pair <int,int> c[n];
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        a[i]=x;
        if(!g1.count(x))
        {
            keys1.push_back(x);
            g1[x]=1;
        }
        else
        {
            g1[x]++;
        }
        b[i]=y;
        if(!g2.count(y))
        {
            keys2.push_back(y);
            g2[y]=1;
        }
        else
        {
            g2[y]++;
        }
        c[i]={x,y};
        if(!g3.count(c[i]))
        {
            keys3.push_back(c[i]);
            g3[c[i]]=1;
        }
        else
        {
            g3[c[i]]++;
        }
    }
    int ans=fact[n];
    int ans1=1;
    for(int i=0;i<keys1.size();++i)
    {
        ans1*=fact[g1[keys1[i]]];
        ans1%=p;
    }
    int ans2=1;
    for(int i=0;i<keys2.size();++i)
    {
        ans2*=fact[g2[keys2[i]]];
        ans2%=p;
    }
    bool h=true;
    sort(keys3.begin(),keys3.end());
    for(int i=0;i<(keys3.size()-1);++i)
    {
        if(keys3[i+1].second<keys3[i].second)
        {
            h=false;
            break;
        }
    }
    int ans3;
    if(h)
    ans3=1;
    else
    ans3=0;
    for(int i=0;i<keys3.size();++i)
    {
        ans3*=fact[g3[keys3[i]]];
        ans3%=p;
    }
    ans-=ans1;
    ans-=ans2;
    ans+=ans3;
    ans%=p;
    ans+=p;
    ans%=p;
    cout<<ans;
    return 0;
}