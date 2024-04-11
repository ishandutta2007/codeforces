#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100,M=1e4+100,G=1010,INF=1e18;

int d[M],dist[M][G];

void upd_(int cur,deque<pii>&q,int i,int j,bool add)
{
    if(dist[i][j]!=INF)
        return;
//    cout<<i<<" "<<j<<" <- "<<cur+add<<"\n";
    dist[i][j]=cur+add;
    if(add)
        q.push_back({i,j});
    else
        q.push_front({i,j});
}
#define upd(i,j,add) upd_(cur,q,i,j,add)

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>d[i];
    sort(d+1,d+m+1);
    int g,r;
    cin>>g>>r;
    for(int i=0;i<M;i++)
        for(int j=0;j<G;j++)
            dist[i][j]=INF;
    dist[1][0]=0;
    deque<pii> q{{1,0}};
    while(!q.empty())
    {
        int i=q.front().x,
            j=q.front().y;
        q.pop_front();
        int cur=dist[i][j];
//        cout<<i<<" "<<j<<" -> "<<cur<<"\n";
        if(j==g)
            upd(i,0,1);
        if(i>=2&&j+d[i]-d[i-1]<=g)
            upd(i-1,j+d[i]-d[i-1],0);
        if(i<=m-1&&j+d[i+1]-d[i]<=g)
            upd(i+1,j+d[i+1]-d[i],0);
    }
    int ans=INF;
    for(int j=0;j<=g;j++)
        if(dist[m][j]!=INF)
            ans=min(ans,dist[m][j]*(g+r)+j);
    if(ans==INF)
        ans=-1;
    cout<<ans;
}