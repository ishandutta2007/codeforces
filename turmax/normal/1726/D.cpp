#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e6+5;
int par[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
bool merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return false; par[x]=y;return true;
}
map<pair<int,int>,int> u;
int ans[maxn];
vector<vector<int> > d;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        vector<pair<int,int> > b;u.clear();for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;b.push_back({x,y});u[{x,y}]=i;}
        for(int i=0;i<n;++i) par[i]=(-1);
        d.clear();
        for(int i=0;i<m;++i)
        {
            int x=b[i].first;int y=b[i].second;
            if(merg(x,y)) continue;
            else d.push_back({x,y,i});
        }
        for(int i=0;i<m;++i) ans[i]=0;
        if(d.size()<3) {for(auto h:d) ans[h[2]]=1;}
        else
        {
        ans[d[0][2]]=1;ans[d[1][2]]=1;
        vector<int> h;for(int i=0;i<3;++i) for(int j=0;j<2;++j) h.push_back(d[i][j]);
        sort(h.begin(),h.end());h.erase(unique(h.begin(),h.end()),h.end());
        if(h.size()!=3)
        {
            ans[d[2][2]]=1;
        }
        else
        {
            ans[d[2][2]]=2;
            for(int i=0;i<n;++i) par[i]=(-1);
            merg(d[2][0],d[2][1]);
            for(int i=0;i<m;++i)
            {
                int x=b[i].first;int y=b[i].second;
                if(ans[i]) {continue;}
                if(merg(x,y)) ans[i]=0;
                else {ans[i]=1;}
            }
        }
        }
        for(int i=0;i<m;++i)
        {
            if(ans[i]==1) cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}