#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=300000;
int a[maxn];
int l[maxn];
int r[maxn];
vector <int> inv[maxn];
int n;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        l[i]=(i-a[i]);
        r[i]=(i+a[i]);
        if(l[i]<0)
        {
            l[i]=(-1);
        }
        if(r[i]>=n)
        {
            r[i]=(-1);
        }
        if(l[i]!=(-1))
        {
            inv[l[i]].push_back(i);
        }
        if(r[i]!=(-1))
        {
            inv[r[i]].push_back(i);
        }
    }
    int res[n];
    deque <int> q;
    int is[n];
    bool used[n];
    for(int i=0;i<n;++i)
    {
        if(a[i]%2==0)
        {
            q.push_back(i);
            is[i]=0;
            used[i]=true;
        }
        else
        {
            is[i]=1e18;
            used[i]=false;
        }
    }
    while(!q.empty())
    {
        deque <int> q1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop_front();
            int v;
            for(int i=0;i<inv[x].size();++i)
            {
                v=inv[x][i];
                if(!used[v])
                {
                    q1.push_back(v);
                    is[v]=is[x]+1;
                    used[v]=true;
                }
            }
        }
        q=q1;
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]%2==1)
        {
            res[i]=is[i];
        }
    }
    q.clear();
    for(int i=0;i<n;++i)
    {
        if(a[i]%2==1)
        {
            q.push_back(i);
            is[i]=0;
            used[i]=true;
        }
        else
        {
            is[i]=1e18;
            used[i]=false;
        }
    }
    while(!q.empty())
    {
        deque <int> q1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop_front();
            int v;
            for(int i=0;i<inv[x].size();++i)
            {
                v=inv[x][i];
                if(!used[v])
                {
                    q1.push_back(v);
                    is[v]=is[x]+1;
                    used[v]=true;
                }
            }
        }
        q=q1;
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]%2==0)
        {
            res[i]=is[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(res[i]==1e18)
        {
            cout<<(-1)<<" ";
        }
        else
        {
            cout<<res[i]<<" ";
        }
    }
    return 0;
}