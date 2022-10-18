#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

vector<int> g[N];
int cnt0[N],score0[N];
int cnt[N],score[N];
int ans;

void calc(int v,int p)
{
    cnt0[v]=score0[v]=0;
    for(int to:g[v])
        if(to!=p)
            cnt0[v]+=cnt0[to],
            score0[v]+=score0[to];
    cnt0[v]++;
    score0[v]+=cnt0[v];
    ans=max(ans,score0[v]);
    cnt[v]=cnt0[v];
    score[v]=score0[v];
}

void recalc(int v,int p,int to)
{
    cnt[v]=cnt0[v];
    score[v]=score0[v];
    score[v]-=cnt0[v];

    score[v]+=score[p];
    score[v]-=score0[to];
    cnt[v]+=cnt[p];
    cnt[v]-=cnt0[to];

    score[v]+=cnt[v];
    ans=max(ans,score[v]);
}

void dfs1(int v,int p)
{
    for(int to:g[v])
        if(to!=p)
            dfs1(to,v);
    calc(v,p);
}

void dfs2(int v,int p)
{
    recalc(v,p,0);
    for(int to:g[v])
        if(to!=p)
        {
            recalc(v,p,to);
            dfs2(to,v);
        }
    recalc(v,0,0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    cout<<ans;
}