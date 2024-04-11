#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
map<pair<int,int>,pair<int,int> > u;
unordered_map<int,int> u1[200005];
unordered_map<int,vector<int> > g;
vector<int> ans;
int b[1000005];vector<int> v[1000005];
void check(int i,int j,int num)
{
    int l=u1[i][num];int r=u1[j][num];
            int ans1=l+r;
            if(ans1>ans[0]) ans={ans1,i,j};
            return;

}
bool add(pair<int,int> pos,int val,int id)
{
    if(!u.count(pos)) {u[pos]={val,id};       g[pos.second].push_back(id);for(int x:g[pos.second])
    {
        if(x!=id)
        check(x,id,pos.second);
    }
return true;}
    pair<int,int> o=u[pos];
    if(make_pair(val,id)>o)
    {
       u[pos]={val,id};
       int pos1=0;while(g[pos.second][pos1]!=o.second) ++pos1;
       g[pos.second].erase(g[pos.second].begin()+pos1);
       g[pos.second].push_back(id);
       for(int x:g[pos.second])
    {
        if(x!=id)
        check(x,id,pos.second);
    }
    return true;
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ans.resize(3);ans[0]=(-1);
    int n;cin>>n;pair<int,int> c[n];int h[n];for(int i=0;i<n;++i) {cin>>c[i].first;c[i].second=i;}
    sort(c,c+n);for(int i=0;i<n;++i) h[i]=c[i].second; int a[n];
    for(int i=0;i<n;++i) {a[i]=c[i].first;b[i]=a[i];v[i].push_back(a[i]);u1[i][a[i]]=0;if(!add({-1,a[i]},0,i)) break;int cyc=0;
    while(a[i]) {++cyc;int was=a[i];int k=1;while(k<a[i]) k*=2; a[i]=k-a[i];v[i].push_back(a[i]);u1[i][a[i]]=cyc;if(!add({was,a[i]},cyc,i)) break;}}
    cout<<h[ans[1]]+1<<' '<<h[ans[2]]+1<<' '<<ans[0];
    return 0;
}