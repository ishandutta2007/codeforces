#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxa=1000005;
vector <int> g[maxa];
bool used[maxa];
int le[maxa];
int ans=1e18;
vector <int> h;
int is[maxa];
int pr[maxa];
void bfs(int x)
{
    deque <int> q;
    q.push_back(x);
    for(int i=0;i<h.size();++i)
    {
        if(h[i]==x)
        {
            is[h[i]]=0;
        }
        else
        {
            is[h[i]]=1e18;
        }
    }
    used[x]=true;
    pr[x]=(-1);
    while(!q.empty())
    {
        deque <int> q1;
        while(!q.empty())
        {
            int z=q.front();
            q.pop_front();
            for(int i=0;i<g[z].size();++i)
            {
                int v=g[z][i];
                if(used[v] && v!=pr[z])
                {
                    /*cout<<pr[z]<<" tgrfde "<<endl;
                    cout<<v<<" "<<z<<" "<<x<<" "<<is[v]+is[z]+1<<endl;*/
                    ans=min(ans,is[z]+is[v]+1);
                }
                else if(!used[v])
                {
                    used[v]=true;
                    q1.push_back(v);
                    pr[v]=z;
                    is[v]=is[z]+1;
                }
            }
        }
        q=q1;
    }
    for(int i=0;i<h.size();++i)
    {
        used[h[i]]=false;
    }
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1)
    {
        return v;
    }
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
vector <int> go(vector <int> v)
{
    sort(v.begin(),v.end());
    int t=0;
    while(t<(int) v.size()-1)
    {
        if(v[t]==v[t+1])
        {
            v.erase(v.begin()+t);
            v.erase(v.begin()+t);
        }
        else
        {
            ++t;
        }
    }
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    vector <int> b[n];
    set <vector<int> > d;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        b[i]=go(rasl(x));
        if(d.count(b[i]))
        {
            ans=min(ans,2LL);
        }
        else
        {
            d.insert(b[i]);
        }
        if(b[i].empty())
        {
            cout<<1<<endl;
            return 0;
        }
        else if(b[i].size()==1)
        {
            b[i].push_back(1000001);
        }
    }
    vector <pair<int,int> > z(n);
    for(int i=0;i<n;++i)
    {
        z[i]={b[i][0],b[i][1]};
        g[z[i].first].push_back(z[i].second);
        g[z[i].second].push_back(z[i].first);
    }
    for(int i=0;i<maxa;++i)
    {
        if(g[i].size())
        {
            h.push_back(i);
        }
    }
    for(int i=2;i<1005;++i)
    {
        if(rasl(i).size()==1)
        bfs(i);
    }
    bfs(1000001);
    if(ans==1e18)
    {
        cout<<(-1);
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}