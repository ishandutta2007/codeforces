#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector<pair<int,int> > a[maxn];vector<pair<int,int> > b[maxn];
bool used[maxn];int is[maxn];int pr[maxn];set<pair<int,int> > d;bool ok[maxn];bool ok1[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int p,q;cin>>q>>p;
    string s[n];for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            ok1[i*m+j]=true;
            if(s[i][j]=='#') {ok1[i*m+j]=false;}
            if(s[i][j]=='.') {ok[i*m+j]=true;continue;}
            if(s[i][j]=='L')
            {
                if(i>=1)
                b[i*m+j].push_back({(i-1)*m+(j+1),q});
                if(i<n-1)
                b[i*m+j].push_back({(i+1)*m+(j+1),q});
                if(j<m-2)
                b[i*m+j].push_back({i*m+j+2,p});
            }
            if(s[i][j]=='R')
            {
                if(i>=1)
                b[i*m+j].push_back({(i-1)*m+(j-1),q});
                if(i<n-1)
                b[i*m+j].push_back({(i+1)*m+(j-1),q});
                if(j>=2)
                b[i*m+j].push_back({i*m+j-2,p});
            }
            if(s[i][j]=='D')
            {
                if(j>=1)
                b[i*m+j].push_back({(i-1)*m+(j-1),q});
                if(j<m-1)
                b[i*m+j].push_back({(i-1)*m+(j+1),q});
                if(i>=2)
                b[i*m+j].push_back({(i-2)*m+j,p});
            }
            if(s[i][j]=='U')
            {
                if(j>=1)
                b[i*m+j].push_back({(i+1)*m+(j-1),q});
                if(j<m-1)
                b[i*m+j].push_back({(i+1)*m+(j+1),q});
                if(i<n-2)
                b[i*m+j].push_back({(i+2)*m+j,p});
            }
        }
    }
    int sz=n*m;
    for(int i=0;i<sz;++i)
    {
        for(auto [x,w]:b[i])
        {
            a[x].push_back({i,w});
        }
    }
    for(int i=0;i<sz;++i)
    {
        if(ok[i]) {is[i]=0;pr[i]=i;}
        else {is[i]=1e18;}
    }
    for(int i=0;i<sz;++i) d.insert({is[i],i});
    while(!d.empty())
    {
        pair<int,int> o=(*d.begin());d.erase(d.begin());int x=o.second;int w=o.first;
        if(!ok1[x]) continue;
        used[x]=true;
        for(auto [v,w]:a[x])
        {
            if(!ok1[v]) continue;
            if(!used[v] && is[v]>is[x]+w)
            {
                pr[v]=pr[x];
                d.erase({is[v],v});is[v]=is[x]+w;d.insert({is[v],v});
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(j<m-1 && s[i][j]!='*' && s[i][j+1]!='*')
            {
                ans=min(ans,is[i*m+j]+is[i*m+j+1]);
            }
            if(i<n-1 && s[i][j]!='*' && s[i+1][j]!='*')
            {
                ans=min(ans,is[i*m+j]+is[(i+1)*m+j]);
            }
        }
    }
    if(ans==1e18) cout<<(-1);
    else cout<<ans;
    return 0;
}