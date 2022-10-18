#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1.1e6+100;

int n;
int a[N],b[N];
int mx[N];
vector<pair<pii,pii>> g[N];
//int deg[N];
bool used[N];

void dfs1(int v)
{
    if(used[v])
        return;
    used[v]=true;
    for(auto to:g[v])
        dfs1(to.x.x);
}

void dfs2(int v)
{
    while(!g[v].empty())
    {
        auto to=g[v].back();
        g[v].pop_back();
        if(used[to.x.y])
            continue;
        used[to.x.y]=true;
        dfs2(to.x.x);
        printf("%d %d ",to.y.y,to.y.x);
    }
}

void solve(int ans)
{
    int pw=1<<ans,pw1=pw-1;
//    for(int i=0;i<pw;i++)
//        deg[i]=0;
//    for(int i=1;i<=n;i++)
//    {
//        deg[a[i]&(pw1)]^=1;
//        deg[b[i]&(pw1)]^=1;
//    }
//    for(int i=0;i<pw;i++)
//        if(deg[i])
//            return;
    for(int i=0;i<pw;i++)
        g[i].clear();
    for(int i=1;i<=n;i++)
    {
        g[a[i]&(pw1)].push_back({{b[i]&(pw1),i},{(i<<1)-1,(i<<1)}});
        g[b[i]&(pw1)].push_back({{a[i]&(pw1),i},{(i<<1),(i<<1)-1}});
    }
    for(int i=0;i<pw;i++)
        if(g[i].size()&1)
            return;
    for(int i=0;i<pw;i++)
        used[i]=false;
    dfs1(a[1]&(pw1));
    for(int i=1;i<=n;i++)
        if(!used[a[i]&(pw1)]||!used[b[i]&(pw1)])
            return;
    for(int i=1;i<=n;i++)
        used[i]=false;
    used[1]=true;
    printf("%d\n",ans);
    printf("2 1 ");
    dfs2(b[1]&(pw1));
    exit(0);
}

signed main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    scanf("%d",&n);
    int pw[21],pw1[21];
    for(int ans=20;ans>=0;ans--)
        pw[ans]=1<<ans,
        pw1[ans]=pw[ans]-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",a+i,b+i);
//        a[i]=rand()&pw1[20];
//        b[i]=rand()&pw1[20];
        for(int ans=20;ans>=0;ans--)
        {
            mx[a[i]&pw1[ans]]++;
            mx[b[i]&pw1[ans]]++;
        }
    }
    for(int i=0;i<pw[20];i++)
        g[i].reserve(mx[i]);
    for(int ans=20;ans>=1;ans--)
        solve(ans);
    printf("0\n");
    for(int i=1;i<=2*n;i++)
        printf("%d ",i);
}