#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n,m;
vector<int> d;
vector< vector<pii> > g;
vector<bool> b;
set<int> ans;

bool dfs1(int v)
{
    if(b[v])
        return false;
    b[v]=true;
    int deg=0;
    for(pii i:g[v])
        if(dfs1(i.second))
        {
            ans.insert(i.first);
            deg=(deg+1)%2;
        }
    if(d[v]>=0&&d[v]!=deg)
        return true;
    else
        return false;
}

int dfs2(int v)
{
    if(b[v])
        return 0;
    b[v]=true;
    int res=0;
    for(pii i:g[v])
    {
        int p=dfs2(i.second);
        res+=p;
        if(p%2==1)
            ans.insert(i.first);
    }
    if(d[v]==1)
        res++;
    return res;
}

int main()
{
    cin>>n>>m;
    d.resize(n);
    int dm1=-1;
    set<int> d1;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        if(d[i]==-1)
            dm1=i;
        if(d[i]==1)
            d1.insert(i);
    }
    g.resize(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(make_pair(i,v));
        g[v].push_back(make_pair(i,u));
    }
    if((dm1==-1)&&(int(d1.size())%2==1))
        cout<<-1,exit(0);
    b=vector<bool>(n);
    if(dm1!=-1)
        dfs1(dm1);
    else if(!d1.empty())
        dfs1(*d1.begin());
    cout<<int(ans.size())<<"\n";
    for(int k:ans)
        cout<<k+1<<"\n";
}