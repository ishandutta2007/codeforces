#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <pair<int,int> > > a;
vector <bool> used;
vector <int> pod;
int c;
int s1=0;
int n,m;
int s2=0;
void dfs(int x)
{
    //cout<<x<<" grf "<<endl;
    used[x]=true;
    int v;
    int s=0;
    if(a[x].size()==1 && x!=0)
    {
        pod[x]=1;
        return;
    }
    bool g=true;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i].first;
        //cout<<v<<" rfds "<<endl;
        if(!used[v])
        {
            dfs(v);
            s+=pod[v];
            s2+=(a[x][i].second*min(pod[v],n-pod[v]));
            if(pod[v]%2==1)
            {
                s1+=a[x][i].second;
            }
            if(pod[v]>=(n/2))
            {
                g=false;
            }
        }
    }
    //cout<<s<<endl;
    ++s;
    pod[x]=s;
    //cout<<x<<" "<<pod[x]<<endl;
}
vector <int> corn;
void dfs2(int x)
{
    if(x==c)
    {
        corn[x]=0;
    }
    used[x]=true;
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i].first;
        if(!used[v])
        {
            corn[v]=corn[x]+a[x][i].second;
            dfs2(v);
        }
    }
    s2+=corn[x];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    s1=0;
    s2=0;
    cin>>n;
    n*=2;
    a.clear();
    a.resize(n);
    pod.resize(n);
    corn.resize(n);
    used.resize(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    int x,y,w;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y>>w;
        x--;y--;
        a[x].push_back({y,w});a[y].push_back({x,w});
    }
    dfs(0);
    cout<<s1<<" "<<s2<<endl;
    }
    return 0;
}