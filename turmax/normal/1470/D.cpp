#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector <vector <int> > a;
set <int> ok;
bool used[maxn];
void dfs(int x)
{
    used[x]=true;
    bool can=true;
    for(auto v:a[x])
    {
        if(ok.count(v)) {can=false;break;}
    }
    if(can) ok.insert(x);
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ok.clear();
        for(int i=0;i<n;++i) used[i]=false;
        a.clear();a.resize(n);
        for(int i=0;i<m;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
        }
        dfs(0);
        bool h=true;
        for(int i=0;i<n;++i)
        {
            if(!used[i])
            {
                cout<<"NO"<<'\n';
                h=false;
                break;
            }
        }
        if(!h) continue;
        cout<<"YES"<<'\n';
        cout<<ok.size()<<'\n';
        for(auto h:ok) cout<<h+1<<' ';
        cout<<'\n';
    }
    return 0;
}