#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+555;
vector<pair<int,int> > cur;
int par[maxn];set<pair<int,int> > d[maxn];vector<pair<int,int> > op[maxn];vector<int> que[maxn];map<pair<int,int>,int> res;
int t[4*maxn];
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1) {t[node]=min(t[node],val);return;}
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return t[node];
    if(tl>=r || tr<=l) return 1e9;
    int tm=(tl+tr)/2;
    return min(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
void f(pair<int,int> t,int w)
{
    int l=t.first;int r=t.second;
    op[l].push_back({r,w});
}
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y,int w)
{
    x=get(x);y=get(y);if(x==y) return;
    if(d[x].size()>d[y].size()) swap(x,y);
    cur.clear();
    for(auto h:d[x]) {cur.push_back(h);d[y].insert(h);}
    set<pair<int,int> >::iterator it=d[y].begin();
    d[y].insert({{1e9,1e9}});d[y].insert({{-1e9,-1e9}});
    for(auto h:cur)
    {
        d[y].insert(h);
        set<pair<int,int> >::iterator it=d[y].find(h);
        --it;
        pair<int,int> h2=(*it);
        if(h2.second+1==h.first)
        {
            pair<int,int> o3={h2.first,h.second};
            d[y].erase(h);d[y].erase(h2);h=o3;f(o3,w);d[y].insert(o3);it=d[y].find(o3);
        }
        else {++it;}
        ++it;
        h2=(*it);
        if(h.second+1==h2.first)
        {
            pair<int,int> o3={h.first,h2.second};
            d[y].erase(h);d[y].erase(h2);f(o3,w);d[y].insert(o3);
        }
    }
    d[y].erase({1e9,1e9});d[y].erase({-1e9,-1e9});
    par[x]=y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        res.clear();
        int n,m,q;cin>>n>>m>>q;
        for(int i=0;i<n+5;++i) {op[i].clear();que[i].clear();}
        for(int i=0;i<n+5;++i) {par[i]=(-1);d[i]={{i,i}};f({i,i},0);}
        for(int i=0;i<4*(n+5);++i) t[i]=1e9;
        for(int i=0;i<m;++i)
        {
            int x,y;cin>>x>>y;
            merg(x,y,i+1);
        }
        vector<pair<int,int> > que1;
        while(q--)
        {
            int l,r;cin>>l>>r;
            que1.push_back({l,r});que[l].push_back(r);
        }
        for(int i=0;i<n+5;++i)
        {
            for(auto [r,w]:op[i])
            {
                to(0,0,n+5,r,w);
            }
            for(auto r:que[i])
            {
                res[{i,r}]=get(0,0,n+5,r,n+5);
            }
        }
        for(auto h:que1)
        {
            cout<<res[h]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}