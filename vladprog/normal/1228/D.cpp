#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int N=1e5+100;

vector<int> g[N];
int c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int v=0;
    for(int x:g[1])
    {
        c[x]=-1;
        if(!v)
            v=x;
    }
    if(!v)
        cout<<-1,exit(0);
    for(int i=1;i<=n;i++)
        if(c[i]==0)
            c[i]=1;
    for(int x:g[v])
        if(c[x]==-1)
            c[x]=3;
    for(int i=1;i<=n;i++)
        if(c[i]==-1)
            c[i]=2;
    int cnt[4]={};
    for(int i=1;i<=n;i++)
        cnt[c[i]]++;
    if(!cnt[3])
        cout<<-1,exit(0);
    int rev[4]={0,cnt[2]+cnt[3],cnt[1]+cnt[3],cnt[1]+cnt[2]};
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()!=rev[c[i]])
            cout<<-1,exit(0);
        for(int x:g[i])
            if(c[i]==c[x])
                cout<<-1,exit(0);
    }
    for(int i=1;i<=n;i++)
        cout<<c[i]<<" ";
}