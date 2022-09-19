#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <pair<int,int> > u;
int n;
const int cnt=1e18;
vector <pair<int,int> > h;
pair <int,int> upd(pair <int,int> d,int x)
{
    if(d.first<=x)
    {
        return {x,d.first};
    }
    else if(d.second<=x)
    {
        return {d.first,x};
    }
    return d;
}
int get(int x)
{
    int t=lower_bound(u.begin(),u.end(),make_pair(x,-cnt-10000))-u.begin();
    return min(h[t].first,h[t].first+h[t].second-u[u.size()-1].second);
}
bool check(int x)
{
    vector <pair<int,int> > v=u;
    //cout<<x<<" x "<<endl;
    for(int i=u.size()-1;i>=0;--i)
    {
        if(u[i].first<(x-u[i].second))
        {
            continue;
        }
        int t=get(x-u[i].second);
        //cout<<t<<" t "<<endl;
        if((t+u[i].first)>=x)
        {
            u=v;
            return true;
        }
        u.erase(u.begin()+i);
    }
    u=v;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,k;
    cin>>n>>m>>k;
    vector <bool> b(n);
    for(int i=0;i<n;++i)
    {
        b[i]=false;
    }
    int x;
    for(int i=0;i<k;++i)
    {
        cin>>x;
        x--;
        b[x]=true;
    }
    int y;
    vector <vector <int> > a(n);
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    int is[n];
    bool used[n];
    for(int i=1;i<n;++i)
    {
        used[i]=false;
        is[i]=1e18;
    }
    is[0]=0;
    used[0]=true;
    deque <int> q;
    q.push_back(0);
    int curr=0;
    while(!q.empty())
    {
        deque <int> h;
        h.clear();
        while(!q.empty())
        {
            int x=q.front();
            q.pop_front();
            int v;
            for(int i=0;i<a[x].size();++i)
            {
                v=a[x][i];
                if(!used[v])
                {
                    h.push_back(v);
                    is[v]=(curr+1);
                    used[v]=true;
                }
            }
        }
        ++curr;
        q=h;
    }
    int is1[n];
    bool used1[n];
    for(int i=0;i<(n-1);++i)
    {
        used1[i]=false;
        is1[i]=1e18;
    }
    is1[n-1]=0;
    used1[n-1]=true;
    q.clear();
    q.push_back(n-1);
    curr=0;
    while(!q.empty())
    {
        deque <int> h;
        h.clear();
        while(!q.empty())
        {
            int x=q.front();
            q.pop_front();
            int v;
            for(int i=0;i<a[x].size();++i)
            {
                v=a[x][i];
                if(!used1[v])
                {
                    h.push_back(v);
                    is1[v]=(curr+1);
                    used1[v]=true;
                }
            }
        }
        ++curr;
        q=h;
    }
    int ans=is[n-1];
    for(int i=0;i<n;++i)
    {
        if(b[i])
        u.push_back({is[i],is1[i]});
    }
    sort(u.begin(),u.end());
    pair <int,int> g=make_pair(-1e18,-1e18);
    h.resize(u.size());
    for(int i=(u.size()-1);i>=0;--i)
    {
        g=upd(g,u[i].second);
        //cout<<g.first<<" "<<g.second<<" gtfds a"<<endl;
        h[i]=g;
    }
    int low=1;
    int up=(ans+1);
    int z;
    /*for(int i=0;i<u.size();++i)
    {
        cout<<h[i].first<<" "<<h[i].second<<endl;
    }*/
    while(true)
    {
        if((up-low)==1)
        {
            ans=min(ans,low);
            cout<<ans;
            return 0;
        }
        z=(low+up)/2;
        if(check(z-1))
        {
            low=z;
        }
        else
        {
            up=z;
        }
    }
    cout<<ans;
    return 0;
}