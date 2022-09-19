#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
typedef pair<int,int> pt;
typedef pair<pt,pt> edge;
vector <edge> g[maxn];
set <edge> ban;
int ptr[maxn];
vector <vector <char> > ans;
void dfs(int x)
{
    for(int i=ptr[x];i<g[x].size();++i)
    {
        if(i<ptr[x]) {i=ptr[x];continue;}
        ++ptr[x];
        edge ed=g[x][i];
        if(ban.count(ed)) continue;
        else
        {
            if(x==ed.first.first)
            {ans[ed.first.first][ed.first.second]='L';
            ans[ed.second.first][ed.second.second]='R';}
            else
            {ans[ed.first.first][ed.first.second]='R';
            ans[ed.second.first][ed.second.second]='L';}
            ban.insert(ed);
            dfs(ed.first.first+ed.second.first-x);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a[n];
    map <int,pt> last;
    vector <edge> v;
    for(int i=0;i<n;++i)
    {
        int c;cin>>c;a[i].resize(c);
        for(int j=0;j<c;++j) cin>>a[i][j];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<a[i].size();++j)
        {
            int el=a[i][j];
            if(!last.count(el) || last[el]==make_pair((int) -1,(int) -1))
            {
                last[el]={i,j};
            }
            else
            {
                v.push_back({last[el],{i,j}});
                last[el]={-1,-1};
            }
        }
    }
    for(int i=0;i<n;++i) {vector <char> v;v.resize(a[i].size());for(auto &h:v) h='$';ans.push_back(v);}
    for(auto ed:v)
    {
        g[ed.first.first].push_back(ed);g[ed.second.first].push_back(ed);
    }
    for(int i=0;i<n;++i)
    {
        if(ptr[i]!=g[i].size()) dfs(i);
    }
    for(int i=0;i<n;++i)
    {
        for(auto h:ans[i]) if(h=='$') {cout<<"NO";return 0;}
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<ans[i].size();++j) cout<<ans[i][j];
        cout<<'\n';
    }
    return 0;
}