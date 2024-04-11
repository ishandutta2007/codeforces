#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<vector<int> > a;
int n,m;
int ans=0;
bool check(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m) return true;
    if(a[x][y]==1) return true;
    if(x>=1 && a[x-1][y]<a[x][y]) return true;
    if(y>=1 && a[x][y-1]<a[x][y]) return true;
    if(x<n-1 && a[x+1][y]<a[x][y]) return true;
    if(y<m-1 && a[x][y+1]<a[x][y]) return true;
    return false;
}
vector<pair<pair<int,int>,pair<int,int> > > res;
void go(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m) return;
    int ans1=ans;
    vector<pair<int,int> > h;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            ans=ans1;
            h.clear();
            h.push_back({x,y});h.push_back({x-1,y});h.push_back({x+1,y});h.push_back({x,y+1});h.push_back({x,y-1});
            h.push_back({i,j});h.push_back({i-1,j});h.push_back({i+1,j});h.push_back({i,j+1});h.push_back({i,j-1});
            sort(h.begin(),h.end());h.erase(unique(h.begin(),h.end()),h.end());
            for(auto t:h)
            {
                if(!check(t.first,t.second)) --ans;
            }
            swap(a[x][y],a[i][j]);
            for(auto t:h)
            {
                if(!check(t.first,t.second)) ++ans;
            }
            swap(a[x][y],a[i][j]);
            if(ans==0)
            {
                pair<int,int> u={x,y};pair<int,int> v={i,j};
                if(u<v) res.push_back({u,v}); else res.push_back({v,u});
               continue;
            }
        }
    }
    ans=ans1;
}
int32_t main()
{
    cin>>n>>m;a.resize(n);for(int i=0;i<n;++i) a[i].resize(m);
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
    pair<int,int> o;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(!check(i,j)) {o={i,j};++ans;}
    if(ans==0) {cout<<0;return 0;}
    go(o.first,o.second);go(o.first-1,o.second);go(o.first+1,o.second);go(o.first,o.second-1);go(o.first,o.second+1);
    sort(res.begin(),res.end());res.erase(unique(res.begin(),res.end()),res.end());
    if(res.size()) {cout<<1<<' '<<res.size();return 0;}
    cout<<2;
    return 0;
}