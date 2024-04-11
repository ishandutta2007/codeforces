#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int par[maxn];
int lp[maxn];
int we[maxn];
bool ok;
vector <pair<int,int> > was1;
vector <pair<int,int> > was2;
bool ok1;
void brp()
{
    was1.clear();was2.clear();
    ok1=ok;
}
void merg(int x,int y)
{
    int wex=0;
    while(par[x]!=(-1)) {wex^=we[x];x=par[x];}
    int wey=0;
    while(par[y]!=(-1)) {wey^=we[y];y=par[y];}
    if(x==y)
    {
        if((wex+wey) & 1) return;
        else {ok=false;return;}
    }
    else
    {
        if(lp[x]<lp[y]) swap(x,y);
        was1.push_back({y,par[y]});was2.push_back({x,lp[x]});
        par[y]=x;we[y]=((wex+wey)&1)^1;lp[x]+=lp[y];
    }
}
void rlb()
{
    ok=ok1;reverse(was1.begin(),was1.end());reverse(was2.begin(),was2.end());
    for(auto h:was1) {par[h.first]=h.second;}
    for(auto h:was2) {lp[h.first]=h.second;}
    was1.clear();was2.clear();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ok=true;
    for(int i=0;i<maxn;++i) {par[i]=(-1);lp[i]=1;}
    int n,m;
    cin>>n>>m;
    pair <int,int> b[m];
    vector <int> que;
    vector <int> z;
    set <pair<int,int> > d;
    vector <bool> ans;
    map <pair<int,int>,int> u;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        --x;--y;
        if(!u.count({x,y})) u[{x,y}]=i;
        int cur=u[{x,y}];
        z.push_back(cur);
        b[i]={x,y};
        if(!d.count({x,y})) {
        d.insert({x,y});
        que.push_back(1);
        }
        else{
            d.erase({x,y});
            que.push_back(0);
        }
    }
    int sq=500;
    for(int i=0;i<m;i+=sq)
    {
        set <int> d;
        for(int j=0;j<i;++j)
        {
            if(que[j]) d.insert(z[j]);
            else d.erase(z[j]);
        }
        set <int> d1=d;
        for(int j=i;j<min(m,i+sq);++j)
        {
            if(que[j]==0) if(d.count(z[j])) d.erase(z[j]);
        }
        brp();
        for(auto h:d)
        {
            d1.erase(h);
            merg(b[h].first,b[h].second);
        }
        for(int k=i;k<min(m,i+sq);++k)
        {
        for(int j=i;j<=k;++j)
        {
            if(que[j]==0)
            {
                //cout<<j<<" - "<<endl;
                d1.erase(z[j]);
            }
            else
            {
                //cout<<j<<" + "<<endl;
                d1.insert(z[j]);
            }
        }
        brp();
        for(auto h:d1) {merg(b[h].first,b[h].second);}
        ans.push_back(ok);
        //cout<<ok<<" ok "<<endl;
        rlb();
        //for(int i=0;i<n;++i) cout<<par[i]<<' ';
        //cout<<endl;
        }
        rlb();
    }
    for(int i=0;i<m;++i)
    {
        cout<<(ans[i] ? "YES" : "NO")<<'\n';
    }
    return 0;
}