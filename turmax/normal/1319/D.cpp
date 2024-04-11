#include <bits/stdc++.h>

using namespace std;
#define int long long
bool cou(vector <int> v,int x)
{
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==x)
        {
            return true;
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <int> a[n];
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[y].push_back(x);
    }
    int t;
    cin>>t;
    vector <int> v(t);
    for(int i=0;i<t;++i)
    {
        cin>>v[i];
        v[i]--;
    }
    bool used[n];
    int is[n];
    vector <int> h[n];
    for(int i=0;i<n;++i)
    {
        is[i]=1e18;
        used[i]=false;
    }
    int x=v[t-1];
    is[x]=0;
    used[x]=true;
    deque <int> q;
    q.push_back(x);
    while(!q.empty())
    {
        deque <int> q1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop_front();
            for(int i=0;i<a[u].size();++i)
            {
                int v=a[u][i];
                if(!used[v])
                {
                    h[v].push_back(u);
                    q1.push_back(v);
                    is[v]=is[u]+1;
                    used[v]=true;
                }
                else if(is[v]==(is[u]+1))
                {
                    h[v].push_back(u);
                }
            }
        }
        q=q1;
    }
    int v1,v2;
    int mi=0,ma=0;
    for(int i=0;i<(v.size()-1);++i)
    {
        v1=v[i];
        v2=v[i+1];
        if(!cou(h[v1],v2))
        {
            //cout<<i<<" i "<<h[v1].size()<<endl;
            ++mi;
        }
        if(h[v1].size()!=1 || h[v1][0]!=v2)
        {
            ++ma;
        }
    }
    cout<<mi<<" "<<ma<<endl;
    return 0;
}