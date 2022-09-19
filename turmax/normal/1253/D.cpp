#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <bool> used;
vector <int> cmp;
int curr;
vector <int> parent;
vector <int> lp;
vector <vector <int> > a;
void dfs(int x,int c)
{
    cmp[x]=c;
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used[a[x][i]])
        {
            dfs(a[x][i],c);
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
        else
        {
            y=parent[y];
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    a.resize(n);
    used.resize(n);
    cmp.resize(n);
    curr=0;
    int x,y;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            dfs(i,curr);
            ++curr;
        }
    }
    vector <int> l(curr);
    parent.resize(curr);
    lp.resize(curr);
    for(int i=0;i<curr;++i)
    {
        l[i]=1e18;
        parent[i]=(-1);
        lp[i]=1;
    }
    for(int i=0;i<n;++i)
    {
        x=cmp[i];
        l[x]=min(l[x],i);
    }
    int ans=0;
    for(int i=(n-1);i>=0;i--)
    {
        x=glav(cmp[i]);
        if(i==0)
        {
            cout<<ans;
            return 0;
        }
        y=glav(cmp[i-1]);
        if(x==y)
        {
            continue;
        }
        else
        {
            // cout<<i<<" "<<x<<" "<<cmp[x]<<endl;
            if(l[x]<i)
            {
                ++ans;
                if(lp[x]>=lp[y])
                {
                    parent[y]=x;
                    lp[x]+=lp[y];
                    l[x]=min(l[x],l[y]);
                }
                else
                {
                    parent[x]=y;
                    lp[y]+=lp[x];
                    l[y]=min(l[x],l[y]);
                }
            }
        }
    }
    return 0;
}