#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int maxn=2e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

int n,m,cnt[maxn],w[maxn],vis[maxn];
vi ans;
vector<pii>v[maxn];

void dfs(int a)
{
    vis[a]=1;
    for(auto i:v[a])if(!vis[i.x])
    {
        cnt[i.x]--;
        ans.push_back(i.y);
    }
    for(auto i:v[a])if(!vis[i.x])
    {

        if(cnt[i.x]<=w[i.x])
            dfs(i.x);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    for(int i=1;i<=m;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        cnt[a]++;
        cnt[b]++;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }

    for(int i=1;i<=n;i++)if(!vis[i])
    {
        if(cnt[i]<=w[i])dfs(i);
    }
    if(ans.size()!=m)
    {
        puts("DEAD");
    }
    else
    {
        puts("ALIVE");
        for(int i=ans.size()-1;~i;i--)
        {
            printf("%d ",ans[i]);
        }
    }
}