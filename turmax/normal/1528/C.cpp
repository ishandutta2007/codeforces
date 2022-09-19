#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector <int> cha[maxn];
vector <int> chb[maxn];
int timer=0;
int tin[maxn];
int tout[maxn];
set <pair<int,int> > d;
vector <pair<int,int> > ch;
int ans;
void dfs1(int x)
{
    tin[x]=timer;
    ++timer;
    for(auto v:chb[x])
    {
        dfs1(v);
    }
    ++timer;
    tout[x]=timer;
}
bool pred(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
void rev()
{
    while(true)
    {
        pair<int,int> z=ch.back();
        ch.pop_back();
        if(z.first==0)
        {
            return;
        }
        else if(z.first==1)
        {
            int x=z.second;
            d.erase({tin[x],x});
        }
        else
        {
            int x=z.second;
            d.insert({tin[x],x});
        }
    }
}
void dfs2(int x)
{
    ch.push_back({0,0});
    d.insert({tin[x],x});
    ch.push_back({1,x});
    set <pair<int,int> >::iterator it=d.find({tin[x],x});
    if(it!=d.begin())
    {
        it--;
        int o=(*it).second;
        if(pred(o,x))
        {
            ch.push_back({-1,o});
            d.erase({tin[o],o});
        }
    }
    ans=max(ans,(int) d.size());
    for(auto v:cha[x])
    {
        dfs2(v);
    }
    rev();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;++i) {cha[i].clear();chb[i].clear();}
        d.clear();
        ch.clear();
        ans=0;
        timer=0;
        for(int i=0;i<(n-1);++i)
        {
            int x;
            cin>>x;
            cha[x-1].push_back(i+1);
        }
        for(int i=0;i<(n-1);++i)
        {
            int x;
            cin>>x;
            chb[x-1].push_back(i+1);
        }
        dfs1(0);
        dfs2(0);
        cout<<ans<<'\n';
    }
    return 0;
}