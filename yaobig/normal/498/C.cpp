#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 4000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int from[maxn+5];
bool used[maxn+5];
int ans,n,m;
vi e[maxn+5];

bool match(int u)
{
    for(auto v: e[u])
    {
        if(!used[v])
        {
            used[v]=1;
            if(from[v]==-1 || match(from[v]))
            {
                from[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int n)
{
    int tot=0;
    memset(from,-1,sizeof from);
    rep(i,1,n)
    {
        memset(used,0,sizeof used);
        if(match(i)) tot++;
    }
    return tot;
}

vector<pii> p[maxn+5];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int tot=0;
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        for(int j=2;1ll*j*j<=x;j++)
        {
            while(x%j==0)
            {
                p[i].pb(mp(j,++tot));
                x/=j;
            }
        }
        if(x>1) p[i].pb(mp(x,++tot));
    }
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        if(y&1) swap(x,y);
        for(auto px: p[x]) for(auto py: p[y]) if(px.first==py.first)
            e[px.second].pb(py.second);
    }
    printf("%d\n",hungary(tot));
    return 0;
}