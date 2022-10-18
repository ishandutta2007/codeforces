#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510,INF=1e9;

vector<pii> g[N];
int dist[N],pred[N];
bool odd[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            if(k-j<=i&&j<=n-i)
                g[i].push_back({i+j-(k-j),j});
    for(int i=0;i<=n;i++)
        dist[i]=INF;
    dist[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto[to,p]:g[v])
            if(dist[to]==INF)
                dist[to]=dist[v]+1,
                pred[to]=p,
                q.push(to);
    }
    if(dist[0]==INF)
        cout<<-1,exit(0);
    int ans=0;
    while(true)
    {
        int cur=0;
        for(int i=1;i<=n;i++)
            cur+=odd[i];
        if(cur==n)
            break;
        int q=pred[cur],
            p=k-q;
//        cout<<cur<<" -> "<<p<<" "<<q<<endl;
        cout<<"? ";
        for(int i=1;i<=n;i++)
            if(!odd[i]&&p>0)
                cout<<i<<" ",
                odd[i]=true,
                p--;
            else if(odd[i]&&q>0)
                cout<<i<<" ",
                odd[i]=false,
                q--;
        cout<<endl;
        int x;
        cin>>x;
        ans^=x;
    }
    cout<<"! "<<ans;
}