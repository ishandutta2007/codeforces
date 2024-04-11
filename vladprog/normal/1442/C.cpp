#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,
          MOD=998244353,
          LOG=22,
          INF=1e18,
          MANY=1e10;

vector<int> g[N];
vector<int> r[N];
int dist[N][LOG+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;

    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        r[v].push_back(u);
    }

//    cin>>n;
//    for(int i=2;i<=n;i+=2)
//    {
//        g[i].push_back(i-1),
//        r[i-1].push_back(i);
//        if(i+1<=n)
//            g[i].push_back(i+1),
//            r[i+1].push_back(i);
//    }

    for(int i=1;i<=n;i++)
        for(int j=0;j<=LOG;j++)
            dist[i][j]=INF;
    int ans=INF;
    set<pair<int,pii>> s;
    s.insert({0,{1,0}});
    dist[1][0]=0;
    while(!s.empty())
    {
        int d=s.begin()->x,
            v=s.begin()->y.x,
            k=s.begin()->y.y;
        s.erase(s.begin());
        if(v==n)
            ans=min(ans,d);
        for(int to:(k%2?r:g)[v])
            if(dist[to][k]>d+1)
                s.erase({dist[to][k],{to,k}}),
                dist[to][k]=d+1,
                s.insert({dist[to][k],{to,k}});
        int k1=k,d1=d;
        if(k==LOG-1)
            k1++,
            d1+=MANY;
        else if(k==LOG)
            k1--,
            d1+=MANY;
        else
            k1++,
            d1+=1<<k;
        if(dist[v][k1]>d1)
            s.erase({dist[v][k1],{v,k1}}),
            dist[v][k1]=d1,
            s.insert({dist[v][k1],{v,k1}});
    }
    int cnt=ans/MANY;
//    cout<<cnt<<"\n";
    ans%=MANY;
    int pw=1;
    while(cnt--)
        pw=pw*2%MOD;
    pw--;
    pw=(pw<<(LOG-1))%MOD;
    ans=(ans+pw)%MOD;
    cout<<ans;
}