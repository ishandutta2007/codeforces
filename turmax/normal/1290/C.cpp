#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> parent;
vector <int> lp;
vector <int> t;
vector <int> color;
vector <bool> d;
int ans;
void go2(int x)
{
    color[x]++;
    color[x]%=2;
    ans+=(lp[x]-2*t[x]);
    t[x]=lp[x]-t[x];
}
void go(int x)
{
    d[x]=true;
    color[x]++;
    color[x]%=2;
    ans+=(lp[x]-2*t[x]);
    t[x]=lp[x]-t[x];
}
void merg(int x,int y,bool h)
{
    if(x==y)
    {
        return;
    }
    if(!h && d[x])
    {
        go(y);
    }
    else if(!h && d[y])
    {
        go(x);
    }
    else if(!h)
    {
        if((lp[x]-2*t[x])>=(lp[y]-2*t[y]))
        {
            go2(y);
        }
        else
        {
            go2(x);
        }
    }
    if(lp[x]>=lp[y])
    {
        parent[y]=x;
        lp[x]+=lp[y];
        t[x]+=t[y];
        d[x]=(d[x]||d[y]);
        if(color[x])
        {
            color[y]++;
            color[y]%=2;
        }
    }
    else
    {
        parent[x]=y;
        lp[y]+=lp[x];
        t[y]+=t[x];
        d[y]=(d[x]||d[y]);
        if(color[y])
        {
            color[x]++;
            color[x]%=2;
        }
    }
}
int glav(int x)
{
    int y=x;
    while(true)
    {
        if(parent[y]==(-1))
        {
            return y;
        }
        y=parent[y];
    }
}
int get(int x)
{
    int r=0;
    int y=x;
    while(true)
    {
        if(y==(-1))
        {
            break;
        }
        r+=color[y];
        y=parent[y];
    }
    return r%2;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    parent.resize(k);
    lp.resize(k);
    t.resize(k);
    color.resize(k);
    d.resize(k);
    for(int i=0;i<k;++i)
    {
        parent[i]=(-1);
        lp[i]=1;
        t[i]=0;
        color[i]=0;
        d[i]=false;
    }
    string s;
    cin>>s;
    vector <vector <int> > a(n);
    int x;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            s[i]='1';
        }
        else
        {
            s[i]='0';
        }
    }
    for(int i=0;i<k;++i)
    {
    int c;
    cin>>c;
    for(int j=0;j<c;++j)
    {
    cin>>x;
    x--;
    a[x].push_back(i);
    }
    }
    ans=0;
    int y;
    for(int i=0;i<n;++i)
    {
        if(a[i].size()==1)
        {
            x=a[i][0];
            if((s[i]-'0')!=get(x))
            {
                go(glav(x));
            }
            else
            {
                d[glav(x)]=true;
            }
        }
        else if(a[i].size()==2)
        {
            x=a[i][0];
            y=a[i][1];
            if((get(x)+get(y))%2==(s[i]-'0'))
            {
                merg(glav(x),glav(y),true);
            }
            else
            {
                merg(glav(x),glav(y),false);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}