#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector<int> a[maxn];bool used[maxn];int sub[maxn];int n,k;int k1=0;int c;
vector<pair<int,int> > res;
vector<int> h[maxn];int w[maxn];
int timer=0;int tin[maxn];int tout[maxn];vector<int> ch[maxn];
const double eps=(1e-6);
void go()
{
    double low=0;double up=1;
    while(up-low>1e-10)
    {
        double mid=(low+up)/2;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(i!=c)
            {
                double w1=mid*sub[i];
                int w2=w1+1;
                w2=min(w2,sub[i]);
                while((sub[i]-w2)%2==1) ++w2;
                sum+=w2;
            }
        }
        if(sum>k) up=mid;
        else low=mid;
    }
    double mid=min(1.0,low+eps);
    int sum=0;
    w[c]=0;
    for(int i=0;i<n;++i)
    {
        if(i!=c)
        {
            double w1=mid*sub[i];
            int w2=w1+1;
            w2=min(w2,sub[i]);
            while((sub[i]-w2)%2==1) ++w2;
            w[i]=w2;
            sum+=w2;
        }
    }
    vector<pair<int,int> > h;
    for(int i=0;i<n;++i) if(i!=c) h.push_back({w[i],i});
    sort(h.begin(),h.end());reverse(h.begin(),h.end());
    assert(mid==1 || sum>=k);
    for(int i=0;i<n;++i)
    {
        if(i!=c)
        {
            vector<int> v;v.push_back(w[i]);
            for(int j:ch[i]) v.push_back(w[j]);
            sort(v.begin(),v.end());reverse(v.begin(),v.end());
            int sum1=0;for(int i=1;i<v.size();++i) sum1+=v[i];
            assert(sum1>=v[0]-1);
        }
    }
    for(auto [w1,id]:h)
    {
        if(sum>k)
        {
            w[id]-=2;sum-=2;
        }
    }
    sum=0;for(int i=0;i<n;++i) if(i!=c) {sum+=w[i];}
    if(sum!=k)
    {
        cout<<"NO";
        exit(0);
    }
    for(int i=0;i<n;++i)
    {
        if(i!=c)
        {
            vector<int> v;v.push_back(w[i]);
            for(int j:ch[i]) v.push_back(w[j]);
            sort(v.begin(),v.end());reverse(v.begin(),v.end());
            int sum1=0;for(int i=1;i<v.size();++i) sum1+=v[i];
        }
    }
}
void dfs2(int x)
{
    used[x]=true;h[x].push_back(x);
    set<pair<int,int> > u;int sum=1;
    u.insert({1,x});
    for(int v:a[x])
    {
        if(!used[v])
        {
            dfs2(v);
            u.insert({h[v].size(),v});sum+=h[v].size();
        }
    }
    while(sum>w[x])
    {
        set<pair<int,int> >::iterator it=u.end();--it;auto u1=(*it);--it;auto u2=(*it);
        res.push_back({h[u1.second].back(),h[u2.second].back()});h[u1.second].pop_back();h[u2.second].pop_back();
        u.erase(u1);u.erase(u2);u1.first--;u2.first--;u.insert(u1);u.insert(u2);
        sum-=2;
    }
    if(x==c)
    {
        while(sum>0)
        {
            set<pair<int,int> >::iterator it=u.end();--it;auto u1=(*it);--it;auto u2=(*it);
            res.push_back({h[u1.second].back(),h[u2.second].back()});h[u1.second].pop_back();h[u2.second].pop_back();
            u.erase(u1);u.erase(u2);u1.first--;u2.first--;u.insert(u1);u.insert(u2);
            sum-=2;
        }
    }
    for(int v:a[x])
    {
        if(!used[v])
        {
            if(h[v].size()<h[x].size())
            {
                for(auto v1:h[v]) h[x].push_back(v1);
            }
            else
            {
                h[x].swap(h[v]);
                for(auto v1:h[v]) h[x].push_back(v1);
            }
        }
    }
    used[x]=false;
}
void dfs1(int x)
{
    used[x]=true;tin[x]=timer;++timer;sub[x]=1;
    for(int v:a[x])
    {
        if(!used[v]) {ch[x].push_back(v);dfs1(v);sub[x]+=sub[v];}
    }
    k1+=(sub[x]%2);
    ++timer;tout[x]=timer;
    used[x]=false;
}
void dfs(int x)
{
    used[x]=true;sub[x]=1;bool ok=true;
    for(int v:a[x])
    {
        if(!used[v]) {dfs(v);ok=(ok && sub[v]<=(n/2));sub[x]+=sub[v];}
    }
    ok=(ok && sub[x]>=(n+1)/2);
    if(ok) c=x;
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    dfs1(c);
    if(k<k1 || ((k-k1)%2)!=0) {cout<<"NO";return 0;}
    go();
    dfs2(c);
    cout<<"YES"<<endl;
    for(auto [x,y]:res)
    {
        cout<<x+1<<' '<<y+1<<endl;
    }
    return 0;
}