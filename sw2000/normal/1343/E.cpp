#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

vi e[maxn];
int p[3],dis[3][maxn];
ll arr[maxn];
ll solve()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<3;i++)scanf("%d",p+i);
    for(int i=1;i<=m;i++)scanf("%lld",arr+i);
    sort(arr+1,arr+m+1);
    for(int i=2;i<=m;i++)arr[i]+=arr[i-1];
    for(int i=0;i<m;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=0;i<3;i++)
    {
        queue<int>q;
        q.push(p[i]);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(auto v:e[u])if(v!=p[i]&&dis[i][v]==0)
            {
                dis[i][v]=dis[i][u]+1;
                q.push(v);
            }
        }
    }

    ll ret=linf;
    for(int i=1;i<=n;i++)
    {
//        for(int j=0;j<3;j++)cout<<dis[j][i]<<' ';cout<<endl;
        if(dis[0][i]+dis[1][i]+dis[2][i]<=m)
            ret=min(ret,arr[dis[1][i]]+arr[dis[0][i]+dis[1][i]+dis[2][i]]);
    }

    for(int i=0;i<3;i++)for(int j=1;j<=n;j++)dis[i][j]=0;
    for(int i=0;i<=n;i++)e[i].clear();
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%lld\n",solve());
    }
    return 0;
}