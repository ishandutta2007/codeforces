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

int n,k,dep[maxn],fa[maxn],sum[maxn];
vi e[maxn];

void dfs(int u,int f)
{
    fa[u]=f;
    sum[u]=1;
    for(auto v:e[u])if(v!=f)
    {
        dep[v]=dep[u]+1;
        dfs(v,u);
        sum[u]+=sum[v];
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    ll ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,0);
    priority_queue<pii>q;
    q.push({sum[1]-1,1});
    for(int i=0;i<n-k;i++)
    {
        pii a=q.top();
        int u=a.y;
        ans+=a.x;
        q.pop();
        for(auto v:e[u])if(v!=fa[u])
        {
            q.push({sum[v]-1-dep[v],v});
        }
//        cout<<ans<<endl;
    }
    printf("%lld",ans);
    return 0;
}