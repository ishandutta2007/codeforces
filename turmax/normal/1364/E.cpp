#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int getans(int x,int y)
{
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    int ans;
    cin>>ans;
    if(ans==(-1))
    {
        exit(0);
    }
    return ans;
}
void go1(int x)
{
    //cout<<x<<" x "<<endl;
    int ans[n];
    for(int i=0;i<n;++i)
    {
        if(i==x)
        {
            ans[i]=0;
        }
        else
        {
            ans[i]=getans(x,i);
        }
    }
    cout<<"! ";
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<' ';
    }
    exit(0);
}
void go2(vector <int> v)
{
    //cout<<v[0]<<" "<<v[1]<<" x1x2 "<<endl;
    int x1=v[0];
    int x2=v[1];
    while(true)
    {
        int o=rand()%n;
        if(o==x1 || o==x2)
        {
            continue;
        }
        else
        {
            int ans1=getans(o,x1);
            int ans2=getans(o,x2);
            if(ans1>ans2)
            {
                go1(x2);
            }
            else if(ans2>ans1)
            {
                go1(x1);
            }
        }
    }
}
void go(int x,vector <int> v)
{
    //cout<<v.size()<<" size "<<endl;
    if(v.size()==2)
    {
        go2(v);
    }
    int z[v.size()];
    int h=2047;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]!=x)
        {
            z[i]=getans(v[i],x);
        }
        else
        {
            z[i]=2047+2048;
        }
        h=(h & z[i]);
    }
    //cout<<h<<" h "<<endl;
    if(h==0 || v.size()==1)
    {
        go1(x);
    }
    vector <int> u;
    for(int i=0;i<v.size();++i)
    {
        if(z[i]==h)
        {
            u.push_back(v[i]);
        }
    }
    u.push_back(x);
    int o=rand()%v.size();
    go(v[o],u);
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(time(NULL)+getpid());
    vector <int> v;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        v.push_back(i);
    }
    for(int i=0;i<10;++i)
    {
        int x=rand()%n;
        int ans=2047;
        for(int j=0;j<5;++j)
        {
            int y=rand()%n;
            if(x==y)
            {
                continue;
            }
            ans=(ans & getans(x,y));
        }
        if(__builtin_popcount(ans)<=6)
        {
            go(x,v);
        }
    }
    return 0;
}