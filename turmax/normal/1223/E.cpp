#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <bool> used;
vector <vector <pair<int,int> > > a;
vector <vector <int> > z;
int k;
void dfs(int x,int pr)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used[a[x][i].first])
        {
            dfs(a[x][i].first,x);
        }
    }
    vector <int> l;
    if(a[x].size()==1 && x!=0)
    {
        z[x][0]=0;
        z[x][1]=0;
        return;
    }
    int s=0;
    for(int i=0;i<a[x].size();++i)
    {
        if((a[x][i].first)==pr)
        {
            continue;
        }
        s+=z[a[x][i].first][1];
        l.push_back(max(z[a[x][i].first][0]+a[x][i].second-z[a[x][i].first][1],0LL));
    }
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());
    for(int i=0;i<min((k-1),(long long) (l.size()));++i)
    {
        s+=l[i];
    }
    z[x][0]=s;
    if(k<=l.size())
    {
        s+=l[k-1];
    }
    z[x][1]=s;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int n;
    int x,y,w;
    for(int i=0;i<q;++i)
    {
        cin>>n>>k;
        a.resize(n);
        z.resize(n);
        used.resize(n);
        for(int j=0;j<z.size();++j)
        {
            z[j].resize(2);
        }
        for(int j=0;j<n;++j)
        {
            a[j].clear();
            z[j][0]=0;
            z[j][1]=0;
            used[j]=false;
        }
        for(int j=0;j<(n-1);++j)
        {
            cin>>x>>y>>w;
            x--;
            y--;
            a[x].push_back({y,w});
            a[y].push_back({x,w});
        }
        dfs(0,-1);
        cout<<max(z[0][0],z[0][1])<<endl;
    }
    return 0;
}