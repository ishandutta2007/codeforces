#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
bool ok[maxn];int nxt[maxn];int par[maxn];set <pair<int,int> > o;int cur=0;int cur1[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return; par[x]=y;
}
void add(int x)
{
    cur1[x]=cur;
    o.insert({cur,x});--cur;
}
void del(int x)
{
    o.erase({cur1[x],x});
}
void go()
{
    for(auto h:o)
    {
        if(h.first==1 || ok[h.second]) break;
        ok[h.second]=true;
        pair<int,int> t=(*o.upper_bound(h));
        if(t.first!=1) {merg(h.second,t.second);}
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
         cur=0;o.clear();o.insert({1,1e18});
         int n;cin>>n;
         for(int i=0;i<n;++i) ok[i]=false;
         for(int i=0;i<n;++i) par[i]=(-1);
         vector<int> g;int cnt0=0,cnt1=0;vector<vector<int> > mom;
         pair<int,int> a[n];int c[n];for(int i=0;i<n;++i) {cin>>c[i];cin>>a[i].first>>a[i].second;mom.push_back({a[i].first,0,i});mom.push_back({a[i].second,1,i});}
         sort(mom.begin(),mom.end());
         for(auto h:mom)
         {
             int typ=h[1];int id=h[2];
             if(typ==0)
             {
                 add(id);if(c[id]==0) cnt0++; else cnt1++;
             }
             else
             {
                 del(id);if(c[id]==0) cnt0--; else cnt1--;
             }
             if(cnt0>0 && cnt1>0)
             {
                 go();
             }
         }
         int ans=0;for(int i=0;i<n;++i) if(par[i]==(-1)) ++ans;
         cout<<ans<<'\n';
    }
    return 0;
}