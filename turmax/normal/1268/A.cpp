#include <bits/stdc++.h>

using namespace std;
#define int long long
int ma(vector <int> v)
{
    int ans=(-1);
    for(int i=0;i<v.size();++i)
    {
        ans=max(ans,v[i]);
    }
    return ans;
}
bool h;
vector <int> to(vector <int> v)
{
    int t=ma(v);
    int z;
    if(!h)
    {
        if(v[0]==9)
        {
            for(int i=0;i<v.size();++i)
            {
                v[i]=0;
            }
            return v;
        }
        else
        {
            h=true;
            z=v[0]+1;
            for(int i=0;i<v.size();++i)
            {
                v[i]=z;
            }
            return v;
        }
    }
    else
    {
        for(int i=0;i<v.size();++i)
        {
            v[i]=v[0];
        }
        return v;
    }
}
pair <bool,vector <int> > check(vector <int> a,int k)
{
    int n=a.size();
    vector <int> v;
    bool d=false;
    for(int i=0;i<n;++i)
    {
        if(a[(i%k)]<a[i] && !d)
        {
            return {false,v};
        }
        else if(a[(i%k)]>a[i])
        {
            d=true;
        }
        a[i]=a[(i%k)];
    }
    return {true,a};
}
vector <int> go(vector <int> a,int k)
{
    h=false;
    int n=a.size();
    vector <int> v;
    vector <int> v2;
    vector <int> b(n);
    for(int i=(k-1);i>=0;i--)
    {
        v.clear();
        for(int j=0;(j*k+i)<n;++j)
        {
            v.push_back(a[j*k+i]);
        }
        v2=to(v);
        for(int j=0;(j*k+i)<n;++j)
        {
            b[j*k+i]=v2[j];
        }
    }
    return b;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <int> a(n);
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        a[i]=s[i]-'0';
    }
    vector <int> b=go(a,k);
    pair <int,vector <int> > c=check(a,k);
    if(c.first)
    {
        //cout<<" gfcd "<<endl;
        b=c.second;
    }
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();++i)
    {
        cout<<b[i];
    }
    return 0;
}