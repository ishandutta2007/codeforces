#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
int parent[1<<20];
int lp[1<<20];
int deq[1<<20];
vector <pair<int,int> > g[1<<20];
bool used[maxn];
vector <int> ans;
vector <int> ans1;
void dfs(int x)
{
    //cout<<x<<" x "<<endl;
    int v;
    if(!g[x].empty())
    {
    for(int i=g[x].size()-1;i>=0;i=min(i-1,(int) g[x].size()-1))
    {
        v=g[x][i].first;
        int o=g[x][i].second;
        if(!used[o])
        {
            used[g[x][i].second]=true;
            g[x].erase(g[x].begin()+i);
            dfs(v);
            ans.push_back(o);
        }
        else
        {
            g[x].erase(g[x].begin()+i);
        }
    }
    }
    ans1.push_back(x);
}
int glav(int x)
{
    int y=x;
    while(true)
    {
        if(parent[y]==(-1))
        {
            return y;
        }
        y=parent[y];
    }
}
void merg(int x,int y)
{
    x=glav(x);y=glav(y);
    if(x==y)
    {
        return;
    }
    if(lp[x]>=lp[y])
    {
        parent[y]=x;
        lp[x]+=lp[y];
    }
    else
    {
        parent[x]=y;
        lp[y]+=lp[x];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    int low=(-1);
    int up=21;
    while(true)
    {
        if((up-low)==1)
        {
            break;
        }
        int k=(low+up)/2;
        for(int i=0;i<(1<<k);++i)
        {
            deq[i]=0;
            parent[i]=(-1);
            lp[i]=1;
        }
        pair <int,int> b[n];
        vector <int> v;
        for(int i=0;i<n;++i)
        {
            b[i].first=a[i].first;b[i].second=a[i].second;
            b[i].first%=(1<<k);
            b[i].second%=(1<<k);
            v.push_back(b[i].first);v.push_back(b[i].second);
            merg(b[i].first,b[i].second);
            deq[b[i].first]++;deq[b[i].second]++;
        }
        bool h=true;
        for(int i=0;i<(1<<k);++i)
        {
            //cout<<i<<" i "<<deq[i]<<" deq[i] "<<endl;
            if(deq[i]%2!=0)
            {
                h=false;
                break;
            }
        }
        set <int> h1;
        for(int i=0;i<v.size();++i)
        {
            h1.insert(glav(v[i]));
        }
        if(h1.size()!=1)
        {
            h=false;
        }
        if(h)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
    int k=low;
    cout<<k<<endl;
    for(int i=0;i<n;++i)
    {
        a[i].first%=(1<<k);a[i].second%=(1<<k);
        g[a[i].first].push_back({a[i].second,i});g[a[i].second].push_back({a[i].first,i});
    }
    dfs(a[0].first);
    for(int i=0;i<ans1.size()-1;++i)
    {
        int x=ans[i];
        if(a[x].first==ans1[i])
        {
            cout<<2*x+1<<" "<<2*x+2<<" ";
        }
        else
        {
            cout<<2*x+2<<" "<<2*x+1<<" ";
        }
    }
    return 0;
}