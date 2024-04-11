#include <bits/stdc++.h>

using namespace std;
#define int long long
string ans;
vector <int> a;
vector <int> z;
int s1=0;
void go(vector <int> &v,int n)
{
    if(a==v)
    {
        return;
    }
    if(z==v)
    {
        ans+='R';
        return;
    }
    if(v[n-1]<v[n-2])
    {
        ans+='R';
        reverse(v.begin(),v.end());
    }
    ans+='P';
    ++s1;
    vector <int> g;
    for(int i=(n-1);i>=1;--i)
    {
        g.push_back(v[i]-v[i-1]);
    }
    g.push_back(v[0]);
    for(int i=0;i<n;++i)
    {
        if(g[i]<=0)
        {
            cout<<"IMPOSSIBLE";
            exit(0);
        }
    }
    reverse(g.begin(),g.end());
    go(g,n);
}
void go2(vector <int> v,int n)
{
    if(min(v[0],v[1])<=0)
    {
        cout<<"IMPOSSIBLE";
        exit(0);
    }
    if(a==v)
    {
        return;
    }
    if(z==v)
    {
        ans+='R';
        return;
    }
    if(v[n-1]<v[n-2])
    {
        ans+='R';
        reverse(v.begin(),v.end());
    }
    int r=max(a[0],a[1]);
    if(v[1]<=r)
    {
        cout<<"IMPOSSIBLE";
        exit(0);
    }
    if(r>=v[0] && (v[1]-r)%v[0]==0)
    {
        if(v[0]==min(a[0],a[1]))
        {
            int x=(v[1]-r)/v[0];
            s1+=x;
            if(s1<=(2e5))
            {
                for(int i=0;i<x;++i)
                {
                    ans+='P';
                }
            }
            vector <int> g(2);g[0]=v[0];g[1]=r;
            go2(g,2);
        }
        else
        {
            cout<<"IMPOSSIBLE";
            exit(0);
        }
    }
    else
    {
        int x=v[1]/v[0];
        s1+=x;
        if(s1<=(2e5))
        {
            for(int i=0;i<x;++i)
            {
                ans+='P';
            }
        }
        vector <int> g(2);g[0]=v[0];g[1]=v[1]%v[0];
        go2(g,2);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    a.resize(n);
    vector <int> b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    z=a;
    reverse(z.begin(),z.end());
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    if(n==1)
    {
        if(a[0]==b[0])
        {
            cout<<"SMALL"<<endl;
            cout<<0;
            return 0;
        }
        else
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    if(n!=2)
    {
    go(b,n);
    reverse(ans.begin(),ans.end());
    if(s1<=200000)
    {
    cout<<"SMALL"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans;
    return 0;
    }
    else
    {
    cout<<"BIG"<<endl;
    cout<<s1;
    return 0;
    }
    }
    else
    {
    go2(b,n);
    reverse(ans.begin(),ans.end());
    if(s1<=200000)
    {
    cout<<"SMALL"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans;
    return 0;
    }
    else
    {
    cout<<"BIG"<<endl;
    cout<<s1;
    return 0;
    }
    }
    return 0;
}