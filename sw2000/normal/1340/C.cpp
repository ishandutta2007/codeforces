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
const int maxn = 1e4 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,m,d[maxn],g,r;
bool vis[maxn][1010];

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d",d+i);
    scanf("%d%d",&g,&r);
    sort(d+1,d+1+m);

    int mi=inf;
    vi v={1};
    vis[1][0]=1;
    for(ll t=0;;t+=g+r)
    {
        queue<pii>q;
        for(auto i:v)q.push({i,0});
        v.clear();
        while(!q.empty())
        {
            pii u=q.front();q.pop();
            if(u.x==m)
            {
                mi=min(mi,u.y);
                continue;
            }
            if(u.y==g)
            {
//                cout<<u.x<<endl;
                v.push_back(u.x);
                continue;
            }
            if(u.x!=1&&d[u.x]-d[u.x-1]+u.y<=g&&!vis[u.x-1][d[u.x]-d[u.x-1]+u.y])
            {
                vis[u.x-1][d[u.x]-d[u.x-1]+u.y]=1;
                q.push({u.x-1,d[u.x]-d[u.x-1]+u.y});
            }
            if(u.y+d[u.x+1]-d[u.x]<=g&&!vis[u.x+1][u.y+d[u.x+1]-d[u.x]])
            {
                vis[u.x+1][u.y+d[u.x+1]-d[u.x]]=1;
                q.push({u.x+1,u.y+d[u.x+1]-d[u.x]});
            }
        }

        if(mi!=inf)
        {
            printf("%lld",t+mi);
            return 0;
        }
        else if(v.empty())
        {
            printf("-1");
            return 0;
        }
    }
    return 0;
}