#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int b[maxn];bool used[maxn];vector<int> a[maxn];int deq[maxn];int pr[maxn];
pair<int,int> d[maxn];vector<int> ch[maxn];map<int,int> l[maxn];
set<int> o;mt19937_64 rnd;
vector<pair<int,int> > res;
void dfs1(int x)
{
    used[x]=true;
    vector<int> v1={x};vector <int> v2={b[x]};
    for(int v:a[x])
    {
        if(!used[v])
        {
            ch[x].push_back(v);
            pr[v]=x;
            dfs1(v);
            v1.push_back(d[v].first);v2.push_back(d[v].second);
        }
    }
    sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
    for(int i=0;i<v1.size();++i)
    {
        if(!(upper_bound(v2.begin(),v2.end(),v1[i])-lower_bound(v2.begin(),v2.end(),v1[i]))) d[x].first=v1[i];
        if(!(upper_bound(v1.begin(),v1.end(),v2[i])-lower_bound(v1.begin(),v1.end(),v2[i]))) d[x].second=v2[i];
    }
    if(pr[x]!=(-1)) {l[pr[x]][d[x].first]=x;}
}
void check(int x)
{
    if(b[x]==x) return;
    if(pr[x]!=(-1) && d[x].second==b[x] && d[x].first==b[pr[x]]) {res.push_back({pr[x],x});swap(b[x],b[pr[x]]);check(pr[x]);check(x);return;}
    if(!l[x].count(b[x])) return;
    int v=l[x][b[x]];assert(pr[v]==x);
    if(d[v].second==b[v] && d[v].first==b[x]) {res.push_back({x,v});swap(b[x],b[v]);check(v);check(x);return;}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
    {
        o.clear();
        int n,m;cin>>n>>m;map<pair<int,int>,int> u;for(int i=0;i<n;++i) {cin>>b[i];--b[i];}
        for(int i=0;i<n;++i) {used[i]=false;a[i].clear();deq[i]=0;pr[i]=(-1);}
        for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;u[{x,y}]=i;u[{y,x}]=i;a[x].push_back(y);a[y].push_back(x);deq[x]++;deq[y]++;}
        for(int i=0;i<n;++i)
        {
            if(deq[i]>=1 && !used[i])
            {
                dfs1(i);
            }
        }
        for(int i=0;i<n;++i) used[i]=false;
        for(int i=0;i<n;++i)
        {
            if(deq[i]>=1) check(i);
        }
        for(int i=0;i<n;++i) assert(b[i]==i);
        for(auto h:res) cout<<u[h]+1<<' ';
    }
    return 0;
}