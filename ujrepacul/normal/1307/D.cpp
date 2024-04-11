#include <bits/stdc++.h>

using namespace std;
vector <int> v[200005];
int dsta[200005],dstb[200005];
int vs[200005],n;
vector<int> x;
queue<int>q;
void bfs1 ()
{
    dsta[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int i=0;i<v[a].size();++i)
        {
            if(!dsta[v[a][i]])
            {
                q.push(v[a][i]);
                dsta[v[a][i]]=1+dsta[a];
            }
        }
    }
}
void bfs2 ()
{
    dstb[n]=1;
    q.push(n);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int i=0;i<v[a].size();++i)
        {
            if(!dstb[v[a][i]])
            {
                q.push(v[a][i]);
                dstb[v[a][i]]=1+dstb[a];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int d,i,j,t,mx=1,m,k;
    cin>>n>>m>>k;
    for(i=1;i<=k;++i)
        cin>>vs[i];
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs1();
    bfs2();
    int mx1a=0,mx1b=0,mx2a=0,mx2b=0;
    for(i=1;i<=n;++i)
    {
        --dsta[i];
        --dstb[i];
    }
    for(i=1;i<=k;++i)
    {
        int ci=i;
        i=vs[i];
        int a=dsta[i];
        int b=dstb[i];
        if(a>dsta[mx1a])
            mx2a=mx1a,mx1a=i;
        else if(a>dsta[mx2a])
            mx2a=i;
        if(b>dstb[mx1b])
            mx2b=mx1b,mx1b=i;
        else if(b>dstb[mx2b])
            mx2b=i;
        i=ci;
    }
    mx=0;
    for(i=1;i<=k;++i)
    {
        int ci=i;
        i=vs[i];
        int a=dsta[i];
        int b=dstb[i];
        int mxa,mxb;
        if(mx1b!=i)
            mxb=mx1b;
        else
            mxb=mx2b;
        if(mx1a!=i)
            mxa=mx1a;
        else
            mxa=mx2a;
        mx=max(mx,max(min(a+1+dstb[mxb],b+1+dsta[mxb]),min(a+1+dstb[mxa],b+1+dsta[mxa])));
        i=ci;
    }
    for(int i=1;i<=k;++i)
        x.push_back(dsta[vs[i]]);
    sort(x.begin(),x.end());
    for(i=0;i<x.size()-1;++i)
        mx=max(mx,dstb[1]-max(0,x[i+1]-x[i]-1));
    x.clear();
    for(int i=1;i<=k;++i)
        x.push_back(dstb[vs[i]]);
    sort(x.begin(),x.end());
    for(i=0;i<x.size()-1;++i)
        mx=max(mx,dstb[1]-max(0,x[i+1]-x[i]-1));
    mx=min(mx,dstb[1]);
    cout<<mx;
    return 0;
}