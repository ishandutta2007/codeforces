#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010,INF=2e18;

string s[N];
int dist[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin>>s[i],s[i]='*'+s[i]+'*';
    s[0]=s[n+1]=string(m+2,'*');
    queue<pii> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]==s[i-1][j]||
               s[i][j]==s[i][j-1]||
               s[i][j]==s[i+1][j]||
               s[i][j]==s[i][j+1])
                dist[i][j]=0,
                q.push({i,j});
            else
                dist[i][j]=INF;
    while(!q.empty())
    {
        int x=q.front().x,y=q.front().y;
        q.pop();
        int d=dist[x][y];
        #define add(x,y) if(dist[x][y]==INF) dist[x][y]=d+1,q.push({x,y})
        add(x-1,y);
        add(x,y-1);
        add(x+1,y);
        add(x,y+1);
    }
    while(t--)
    {
        int i,j,p;
        cin>>i>>j>>p;
        int d=dist[i][j];
        if(p<=d||(p-d)%2==0)
            cout<<s[i][j]<<"\n";
        else
            cout<<'1'-s[i][j]<<"\n";
    }
}