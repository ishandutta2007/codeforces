#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=110;

bool eq[N][N][N];
bool used[N][N];
vector<int> g[N];
vector<pair<int,int>> edges;
int d[N];

void comp(int i,int j,int n)
{
    if(i==j)
        return;
    if(used[i][j])
        return;
    used[i][j]=true;
    edges.push_back({i,j});
    comp(j,i,n);
    for(int k=1;k<=n;k++)
    {
        if(eq[i][k][j])
            comp(j,k,n);
        if(eq[j][k][i])
            comp(i,k,n);
    }
}

void dist(int v,int p,int cur)
{
    d[v]=cur;
    for(int to:g[v])
        if(to!=p)
            dist(to,v,cur+1);
}

bool check(int n)
{
    for(int k=1;k<=n;k++)
        if(g[k].empty())
            return false;
    for(int k=1;k<=n;k++)
    {
        dist(k,-1,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if((d[i]==d[j])!=eq[i][j][k])
                    return false;
    }
    return true;
}

bool solve(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            used[i][j]=false,
            eq[i][i][j]=true;
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-i;j++)
            for(int k=1;k<=n;k++)
            {
                char ch;
                cin>>ch;
                ch-='0';
                eq[i][i+j][k]=eq[i+j][i][k]=ch;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            edges.clear();
            comp(i,j,n);
            if(edges.size()!=2*n-2)
                continue;
            for(int k=1;k<=n;k++)
                g[k].clear();
            for(auto[x,y]:edges)
                g[x].push_back(y);
            if(check(n))
                return true;
        }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(solve(n))
        {
            cout<<"Yes\n";
            for(int i=1;i<=n;i++)
                for(int j:g[i])
                    if(i<j)
                        cout<<i<<" "<<j<<"\n";
        }
        else
            cout<<"No\n";
    }
}