#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
vector <int> a[maxn];
bool used[maxn];
vector <pair<int,int> > res;
int sub[maxn];
int pr[maxn];
vector <int> h;
vector <int> b[maxn];
void dfs1(int x)
{
    used[x]=true;
    sub[x]=1;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            b[x].push_back(v);
            pr[v]=x;
            dfs1(v);
            sub[x]+=sub[v];
        }
    }
}
void pl1(vector <int> &q)
{
    while(!q.empty())
    {
        int x=h.back();
        int y=q.back();
        res.push_back({x,y});
        h.pop_back();
        q.pop_back();
    }
}
vector <int> &pl(vector <int> &q1,vector <int> &q2)
{
    while(true)
    {
        if(q1.empty())
        {
            return q2;
        }
        else if(q2.empty())
        {
            return q1;
        }
        else
        {
            int x=q1.back();
            int y=q2.back();
            res.push_back({x,y});
            q1.pop_back();
            q2.pop_back();
        }
    }
}
void go1(vector <vector<int> > &u)
{
    for(int i=0;i<u.size()-1;++i)
    {
        u[i+1]=pl(u[i],u[i+1]);
    }
    h=u[u.size()-1];
}
void go(vector <vector<int> > &u)
{
    if(u.empty()) return;
    for(int i=0;i<u.size();++i)
    {
        if(u[i].size()>=h.size())
        {
            u.push_back(h);
            h.clear();
            go1(u);
            return;
        }
    }
    for(int i=0;i<u.size()-1;++i)
    {
        u[i+1]=pl(u[i],u[i+1]);
    }
    pl1(u[u.size()-1]);
}
void cou(vector <int> q)
{
    while(!q.empty())
    {
        cout<<q.back()<<endl;
        q.pop_back();
    }
}
void dfs(int x)
{
    //cout<<x<<" x begin "<<endl;
    used[x]=true;
    vector <pair<int,int> > o;
    for(auto v:b[x])
    {
        if(!used[v])
        {
            o.push_back({sub[v],v});
        }
    }
    sort(o.begin(),o.end());
    vector <vector<int> > u;
    for(int i=0;i<((int) o.size())-1;++i)
    {
        int v=o[i].second;
        dfs(v);
        u.push_back(h);
        h.clear();
    }
    if(!o.empty())
    {
    dfs(o[o.size()-1].second);
    //cout<<" h "<<endl;
    //cou(h);
    go(u);
    }
    h.push_back(x);
    //cout<<" h "<<endl;
    //cou(h);
    //cout<<x<<" x end "<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    h.clear();
    res.clear();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i) {a[i].clear();used[i]=false;b[i].clear();}
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    pr[0]=(-1);
    dfs1(0);
    for(int i=0;i<n;++i) used[i]=false;
    dfs(0);
    if(4*res.size()>=n)
    {
        cout<<"PAIRING"<<'\n';
        cout<<res.size()<<'\n';
        for(auto h:res)
        {
            cout<<h.first+1<<' '<<h.second+1<<'\n';
        }
        continue;
    }
    else
    {
        int x=h[0];
        vector <int> v;
        while(x!=(-1))
        {
            v.push_back(x);
            x=pr[x];
        }
        cout<<"PATH"<<'\n';
        cout<<v.size()<<'\n';
        for(auto l:v)
        {
            cout<<l+1<<' ';
        }
        cout<<'\n';
        continue;
    }
    }
    return 0;
}