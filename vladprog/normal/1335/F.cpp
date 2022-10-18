#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int n,m;
string c[N],s[N];
int comp[N];
bool used[N];
int dist[N];
int sz[N];
set<int> ok[N];
#define code(x,y) ((x)*m+(y))

void dfs1(int x,int y)
{
    int h=code(x,y);
    if(dist[h])
        return;
    if(used[h])
    {
        dist[h]=1;
        comp[h]=h;
        return;
    }
    used[h]=true;
    int x1=x,y1=y;
    if(s[x][y]=='U')
        x1--;
    else if(s[x][y]=='R')
        y1++;
    else if(s[x][y]=='D')
        x1++;
    else
        y1--;
    int h1=code(x1,y1);
    dfs1(x1,y1);
    comp[h]=comp[h1];
    dist[h]=dist[h1]+1;
}

int dfs2(int x,int y,bool start)
{
    int h=code(x,y);
    if(start&&comp[h]!=h)
        return 0;
    if(!start&&comp[h]==h)
        return 0;
    int x1=x,y1=y;
    if(s[x][y]=='U')
        x1--;
    else if(s[x][y]=='R')
        y1++;
    else if(s[x][y]=='D')
        x1++;
    else
        y1--;
    return sz[h]=dfs2(x1,y1,false)+1;
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
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>c[i];
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<n*m;i++)
            comp[i]=used[i]=dist[i]=sz[i]=0,
            ok[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dfs1(i,j);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dfs2(i,j,true);
        int ans1=0;
        for(int h=0;h<n*m;h++)
            if(comp[h]==h)
                ans1+=sz[h];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(c[i][j]=='0')
                {
                    int h=code(i,j);
                    int h1=comp[h];
                    ok[h1].insert(dist[h]%sz[h1]);
                }
        int ans2=0;
        for(int h=0;h<n*m;h++)
            ans2+=ok[h].size();
        cout<<ans1<<" "<<ans2<<"\n";
    }
}