#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
bool used[maxn];
vector <int> a[maxn];
int deq[maxn];
int li=0;int pc=0;
bool f=true;
int par[maxn];
bool dfs(int x)
{
    used[x]=true;
    bool h=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            par[v]=x;
            h=(dfs(v) && h);
        }
    }
    if(x==0)
    {
        if(deq[x]!=0)
        {
            f=false;
        }
        return false;
    }
    if(deq[x]==1)
    {
        ++li;
        return true;
    }
    if(h)
    {
        ++pc;
        deq[x]--;deq[par[x]]--;
        return true;
    }
    f=false;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        li=0;pc=0;
        f=true;
        int n;
        cin>>n;
        for(int i=0;i<n;++i) a[i].clear();
        for(int i=0;i<n;++i) used[i]=0;
        for(int i=0;i<n;++i) deq[i]=0;
        for(int i=0;i<n-1;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            deq[x]++;deq[y]++;
            a[x].push_back(y);a[y].push_back(x);
        }
        dfs(0);
        //cout<<li<<" li "<<pc<<" pc "<<endl;
        if(f) cout<<(li-pc+1)<<'\n';
        else cout<<(li-pc)<<'\n';
    }
    return 0;
}