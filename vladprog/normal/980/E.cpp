#include <bits/stdc++.h>

using namespace std;

//typedef long long ll;
//#define int ll

const int N=1e6+100;

vector<int> g[N];
int pr[N][20];

void dfs(int v,int p)
{
    pr[v][0]=p;
    for(int to:g[v])
        if(to!=p)
            dfs(to,v);
}

bool b[N];
int sz=0;
void insert(int x)
{
    if(!b[x])
        b[x]=true,sz++;
}
int count(int x)
{
    return b[x];
}
int size()
{
    return sz;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(n,0);
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)
            pr[i][j]=pr[pr[i][j-1]][j-1];
    insert(0);
    for(int i=n;i>=1;i--)
        if(!count(i))
        {
            int t=i,d=0;
            for(int j=19;j>=0;j--)
                if(!count(pr[t][j]))
                    d+=1<<j,
                    t=pr[t][j];
//            cout<<s.size()<<" + "<<d<<" = ";
            if(size()+d<=n-k)
                for(t=i;!count(t);t=pr[t][0])
                    insert(t);
//            cout<<s.size()<<"\n";
        }
    for(int i=1;i<=n;i++)
        if(!count(i))
            cout<<i<<" ";
}