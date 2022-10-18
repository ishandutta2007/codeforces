#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<int> g[N];
int h[N];
bool preleaf[N];
int leaves=0;

bool dfs(int v,int p,int d)
{
    bool res=true;
    h[v]=d;
    bool leaf=true;
    for(int to:g[v])
        if(to!=p)
        {
            if(!dfs(to,v,d+1))
                res=false;
            leaf=false;
        }
    if(leaf)
    {
        preleaf[p]=true;
//        cout<<"\n leaf:"<<v<<"\n";
        leaves++;
        return !(d&1);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int r=-1;
    for(int i=1;i<=n;i++)
        if(g[i].size()==1)
        {
            r=i;
            break;
        }
    if(dfs(r,-1,false))
        cout<<1<<" ";
    else
        cout<<3<<" ";
    int ans=n-leaves-1;
//    cout<<"\n"<<leaves<<"\n";
    for(int i=1;i<=n;i++)
        if(preleaf[i]&&h[i]>1)
            ans++;
    cout<<ans;
}